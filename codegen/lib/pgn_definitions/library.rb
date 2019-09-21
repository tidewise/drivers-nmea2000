module PGNDefinitions
    class Library
        def self.read(path)
            xml = REXML::Document.new(File.read(path)).root
            unless xml.name == 'PGNDefnCollection'
                raise ArgumentError, 'not a XML PGN definition file'
            end

            pgns = xml.enum_for(:each_element, 'PGNDefns/PGNDefn').map do |xml|
                PGN.new(xml)
            end
            new(pgns)
        end

        def initialize(pgns)
            @pgns = pgns.each_with_object({}) { |pgn, h| h[pgn.id] = pgn }
        end

        def from_id(id)
            @pgns.fetch(id)
        end

        def each_pgn(&block)
            @pgns.each_value(&block)
        end
    end
end
