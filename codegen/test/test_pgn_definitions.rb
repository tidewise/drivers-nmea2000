require 'minitest/autorun'
require 'minitest/spec'
require 'pgn_definitions'

require 'rexml/document'

module PGNDefinitions
    describe Field do
        it 'returns the field name' do
            field = make_field('<IntField Name="Bla" />')
            assert_equal 'Bla', field.name
        end

        describe 'integer?' do
            it 'returns true if the field is a IntField' do
                field = make_field('<IntField Name="Bla" />')
                assert field.integer?
            end

            it 'returns true if the field is a UIntField' do
                field = make_field('<UIntField Name="Bla" />')
                assert field.integer?
            end

            it 'returns true if the field is a EnumField' do
                field = make_field('<EnumField Name="Bla" />')
                assert field.integer?
            end

            it 'returns false if the field is neither IntField or UIntField' do
                field = make_field('<DblField Name="Bla" />')
                refute field.integer?
            end
        end

        describe 'unsigned?' do
            it 'returns true if the field is a UIntField' do
                field = make_field('<UIntField Name="Bla" />')
                assert field.unsigned?
            end

            it 'returns true if the field is a UDblField' do
                field = make_field('<UDblField Name="Bla" />')
                assert field.unsigned?
            end

            it 'returns false for if the field is neither' do
                field = make_field('<EnumField Name="Bla" />')
                refute field.unsigned?
            end
        end

        describe 'enum?' do
            it 'returns true if the field is a EnumField' do
                field = make_field('<EnumField Name="Bla" />')
                assert field.enum?
            end

            it 'returns false if the field is not a EnumField' do
                field = make_field('<UDblField Name="Bla" />')
                refute field.enum?
            end
        end

        describe 'float?' do
            it 'returns true if the field is a DblField' do
                field = make_field('<DblField Name="Bla" />')
                assert field.float?
            end

            it 'returns true if the field is a UDblField' do
                field = make_field('<UDblField Name="Bla" />')
                assert field.float?
            end

            it 'returns false if the field is neither a DblField nor a UDblField' do
                field = make_field('<EnumField Name="Bla" />')
                refute field.float?
            end
        end

        describe 'each_enum_value' do
            it 'enumerates the enum values' do
                field = make_field(<<~END_OF_FIELD)
                    <EnumField Name="Control">
                        <EnumValues>
                            <EnumPair Value="0" Name="ACK" />
                            <EnumPair Value="1" Name="NAK" />
                            <EnumPair Value="2" Name="Access Denied" />
                            <EnumPair Value="3" Name="Address Busy" />
                        </EnumValues>
                    </EnumField>
                END_OF_FIELD

                expected = [
                    ['ACK', 0], ['NAK', 1], ['Access Denied', 2], ['Address Busy', 3]
                ]
                assert_equal expected, field.each_enum_value.to_a
            end

            it 'returns true if the field is a UDblField' do
                field = make_field('<UDblField Name="Bla" />')
                assert field.float?
            end

            it 'returns false if the field is neither a DblField nor a UDblField' do
                field = make_field('<EnumField Name="Bla" />')
                refute field.float?
            end
        end

        describe 'bit_offset' do
            it 'returns the bit offset' do
                field = make_field(
                    '<EnumField Name="Bla"><BitOffset>12</BitOffset></EnumField>'
                )
                assert_equal 12, field.bit_offset
            end

            it 'raises if there is no bit offset' do
                field = make_field('<UDblField Name="Bla" />')
                assert_raises(TypeError) { field.bit_offset }
            end
        end

        describe 'bit_length' do
            it 'returns the bit length' do
                field = make_field(
                    '<EnumField Name="Bla"><BitLength>12</BitLength></EnumField>'
                )
                assert_equal 12, field.bit_length
            end

            it 'raises if there is no bit length' do
                field = make_field('<UDblField Name="Bla" />')
                assert_raises(TypeError) { field.bit_length }
            end
        end

        describe 'byte_length' do
            it 'returns the power-of-two byte size that contains the field '\
               'for an exact rounded number' do
                field = make_field(
                    '<EnumField Name="Bla"><BitLength>16</BitLength></EnumField>'
                )
                assert_equal 2, field.byte_length
            end

            it 'returns the power-of-two byte size that contains the field '\
               'for a non-round number' do
                field = make_field(
                    '<EnumField Name="Bla"><BitLength>17</BitLength></EnumField>'
                )
                assert_equal 4, field.byte_length
            end

            it 'handles sizes below 8' do
                field = make_field(
                    '<EnumField Name="Bla"><BitLength>2</BitLength></EnumField>'
                )
                assert_equal 1, field.byte_length
            end

            it 'raises if there is no bit length' do
                field = make_field('<UDblField Name="Bla" />')
                assert_raises(TypeError) { field.byte_length }
            end
        end

        def make_field(xml)
            xml = REXML::Document.new(xml).root
            Field.new(xml)
        end
    end

    describe Library do
        it 'reads the definitions' do
            library = Library.read(File.expand_path('../../pgns.xml', __dir__))
            pgn = library.from_id(59_392)
            assert_equal 'ISO Acknowledgement', pgn.name
        end
    end

    describe PGN do
        before do
            library = Library.read(File.expand_path('../../pgns.xml', __dir__))
            @pgn = library.from_id(59_392)
        end

        it 'returns the id' do
            assert_equal 59_392, @pgn.id
        end

        it 'returns the name' do
            assert_equal 'ISO Acknowledgement', @pgn.name
        end

        it 'returns the byte length' do
            assert_equal 8, @pgn.byte_length
        end

        it 'enumerates the fields' do
            expected = ['Control', 'Group Function', 'Reserved', 'PGN']
            assert_equal expected, @pgn.each_field.map(&:name)
        end
    end

    describe Codegen do
        describe '.make_name_camel_case' do
            it 'converts a simple name into the camelcase equivalent' do
                assert_equal 'ISOAcknowledgement',
                             Codegen.make_name_camel_case('ISO Acknowledgement')
            end

            it 'handles punctuation' do
                assert_equal 'ISOManuProprietarySingleFrameAddressed',
                             Codegen.make_name_camel_case(
                                 'ISO: Manu. Proprietary single-frame addressed'
                             )
            end
        end

        describe '.make_name_snake_case' do
            it 'converts a simple name into the snake case equivalent' do
                assert_equal 'iso_self_configurable',
                             Codegen.make_name_snake_case('ISO Self Configurable')
            end

            it 'converts the hash sign to the word number' do
                assert_equal 'sat_number',
                             Codegen.make_name_snake_case('Sat #')
            end
        end

        describe '.make_enum_value_upper_camel_case' do
            it 'converts a simple name into the upper camel case equivalent' do
                assert_equal 'steering_and_control_surfaces',
                             Codegen.make_name_snake_case('Steering and Control Surfaces')
            end

            it 'handles punctuation' do
                assert_equal 'DECK_CARGO_AND_FISHING_EQUIPMENT',
                             Codegen.make_enum_value_upper_camel_case(
                                 'Deck, Cargo and Fishing Equipment'
                             )
            end
        end
    end
end
