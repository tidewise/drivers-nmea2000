module PGNDefinitions
    class Library
        def self.read(path)
            xml = REXML::Document.new(File.read(path)).root
            unless xml.name == 'PGNDefnCollection'
                raise ArgumentError, 'not a XML PGN definition file'
            end

            pgns = xml.enum_for(:each_element, 'PGNDefns/PGNDefn').map do |defn_xml|
                PGN.new(defn_xml)
            end
            new(pgns)
        end

        def initialize(pgns)
            @pgns = pgns.each_with_object({}) do |pgn, h|
                (h[pgn.id] ||= []) << pgn
            end
        end

        def from_id(id)
            @pgns.fetch(id, [])
        end

        def each_pgn(&block)
            return enum_for(__method__) unless block_given?

            @pgns.each_value do |list|
                list.each(&block)
            end
        end
    end
end
