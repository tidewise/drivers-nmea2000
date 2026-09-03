# frozen_string_literal: true

module PGNDefinitions
    # Representation of a field within a single PGN definition
    #
    # All fields are defined as a certain length of bits with a bit offset from the start
    # For integer types and enums, the decoding logic will decode an integer that contains the
    # field, and then extract the field. The code uses
    # {#integer_decoding_byte_length} to compute the length of that intermediary integer
    #
    # Float types are actually integer on which we apply a scale and offset afterwards for
    # interpretation. So, they are decoded the same way than integer
    #
    # For ASCII fields, it is assumed that the field is byte-aligned. This is verified
    # by {#raw_byte_length}
    class Field
        def initialize(xml)
            @xml = xml
        end

        def name
            @xml.attributes["Name"]
        end

        def byte_offset
            bit_offset / 8
        end

        def bit_offset
            Integer(@xml.text("BitOffset"))
        end

        def bit_length
            Integer(@xml.text("BitLength"))
        end

        def check_unavailable?
            return unless (value = @xml.text("CheckUnavailable"))

            Integer(value) == 1
        end

        def first_unavailable_value
            if unsigned?
                2**bit_length - 3
            else
                2**(bit_length - 1) - 3
            end
        end

        def relative_bit_offset
            bit_offset % 8
        end

        # The length of bytes that should be decoded at the {#bit_offset} / 8 byte offset
        # so that the decoding logic can extract it
        def integer_decoding_byte_length
            total_field_length_in_bits = relative_bit_offset + bit_length
            ((total_field_length_in_bits + 7) / 8)
        end

        # Byte length of a byte-aligned field
        def raw_byte_length
            if (relative_bit_offset != 0) || (bit_length % 8 != 0)
                raise ArgumentError,
                      "cannot call raw_byte_length on a field whose both beginning " \
                      "and end are that is not byte-aligne"
            end

            bit_length / 8
        end

        # Byte length of the C++ struct field needed to contain this field
        #
        # Only applicable if the field is an integer
        def field_byte_length
            2**Math.log2((bit_length / 8.0).ceil).ceil
        end

        SUPPORTED_FIELD_TYPES = %w[
            ASCIIField EnumField IntField UIntField DblField UDblField InstanceField
        ].freeze

        def supported?
            SUPPORTED_FIELD_TYPES.include?(@xml.name) &&
                (relative_bit_offset == 0 && bit_length % 8 == 0) || unsigned?
        end

        def integer?
            %w[EnumField IntField UIntField InstanceField].include?(@xml.name)
        end

        def float?
            %w[DblField UDblField].include?(@xml.name)
        end

        def unsigned?
            @xml.name.start_with?("U") || enum? || instance_field?
        end

        def ascii?
            %w[ASCIIField].include?(@xml.name)
        end

        def instance_field?
            @xml.name == "InstanceField"
        end

        def enum?
            @xml.name == "EnumField"
        end

        def scale
            Float(@xml.text("Scale") || 1)
        end

        def offset
            Float(@xml.text("Offset") || 0)
        end

        def each_enum_value
            return enum_for(__method__) unless block_given?

            @xml.each_element("EnumValues/EnumPair") do |value|
                yield(value.attributes["Name"], Integer(value.attributes["Value"]))
            end
        end
    end
end
