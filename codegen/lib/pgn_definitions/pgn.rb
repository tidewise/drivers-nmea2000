module PGNDefinitions
    class PGN
        def initialize(xml)
            @xml = xml
        end

        def name
            @xml.text('Name')
        end

        def id
            Integer(@xml.attributes['PGN'])
        end

        def byte_length_present?
            @xml.text('ByteLength')
        end

        def byte_length
            Integer(@xml.text('ByteLength'))
        end

        def each_field
            return enum_for(__method__) unless block_given?

            @xml.each_element('Fields/*') do |child|
                next unless child.name =~ /Field/

                yield(Field.new(child))
            end
        end

        def each_enum_field
            return enum_for(__method__) unless block_given?

            each_field do |f|
                yield(f) if f.enum?
            end
        end
    end
end
