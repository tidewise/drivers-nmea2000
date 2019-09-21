module PGNDefinitions
    module Codegen
        def self.make_name_camel_case(string)
            string.gsub(%r{[:\(\)/]}, '')
                  .gsub(/[^\w]\w/) { |s| s[1, 1] = s[1, 1].upcase }
                  .gsub(/\s*[^\w]/, '')
        end

        def self.make_name_snake_case(string)
            string.gsub('#', 'number')
                  .gsub(/[^\w]+/, '_')
                  .downcase
        end

        def self.make_enum_value_upper_camel_case(string)
            string.gsub(/[^\w]+/, '_')
                  .upcase
        end

        def self.pgn_name_to_cxx(name)
            make_name_camel_case(name)
        end

        def self.pgn_enums_to_cxx(pgn)
            pgn.each_enum_field.map do |field|
                values = field.each_enum_value.map do |value_name, value|
                    [make_enum_value_upper_camel_case(value_name),
                     value]
                end
                [make_name_camel_case(field.name), values]
            end
        end

        def self.pgn_field_cxx_type(field)
            return 'float' if field.float?
            return make_name_camel_case(field.name) if field.enum?
            raise ArgumentError, 'unsupported field' unless field.integer?

            "#{'u' if field.unsigned?}int#{field.byte_length * 8}_t"
        end

        def self.pgn_fields_to_cxx(pgn)
            pgn.each_field.map do |field|
                unless field.supported?
                    puts "Skipping unsupported field #{field.name} in #{pgn.name}"
                    next
                end

                cxx_type = pgn_field_cxx_type(field)
                [field, cxx_type, make_name_snake_case(field.name)]
            end.compact
        end

        def self.generate_pgns_hpp(library)
            definitions = library.each_pgn.find_all(&:byte_length_present?)

            template = File.read(File.expand_path('PGNs.hpp.erb', __dir__))
            erb = ERB.new(template, nil, '>')
            erb.location = template
            erb.result(binding)
        end

        def self.generate_pgns_cpp(library)
            definitions = library.each_pgn.find_all(&:byte_length_present?)

            template = File.read(File.expand_path('PGNs.cpp.erb', __dir__))
            erb = ERB.new(template, nil, '>')
            erb.location = template
            erb.result(binding)
        end
    end
end
