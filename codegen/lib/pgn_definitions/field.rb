module PGNDefinitions
    # Representation of a field within a single PGN definition
    class Field
        def initialize(xml)
            @xml = xml
        end

        def name
            @xml.attributes['Name']
        end

        def byte_offset
            bit_offset / 8
        end

        def bit_offset
            Integer(@xml.text('BitOffset'))
        end

        def bit_length
            Integer(@xml.text('BitLength'))
        end

        def relative_bit_offset
            bit_offset % 8
        end

        def byte_length
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
            @xml.name.start_with?('U') || enum? || instance_field?
        end

        def ascii?
            %w[ASCIIField].include?(@xml.name)
        end

        def instance_field?
            @xml.name == "InstanceField"
        end

        def enum?
            @xml.name == 'EnumField'
        end

        def scale
            Float(@xml.text('Scale') || 1)
        end

        def offset
            Float(@xml.text('Offset') || 0)
        end

        def each_enum_value
            return enum_for(__method__) unless block_given?

            @xml.each_element('EnumValues/EnumPair') do |value|
                yield(value.attributes['Name'], Integer(value.attributes['Value']))
            end
        end
    end
end
