#include <string>

namespace log_line {
    int get_header_index(std::string log) {
        return log.find("]: ");
    }
    
    std::string message(std::string log) {
        return log.substr(get_header_index(log) + 3);
    }

    std::string log_level(std::string log) {
        return log.substr(1, get_header_index(log) -1);
    }

    std::string reformat(std::string log) {
        return message(log) + " (" + log_level(log) + ")";
    }

} // namespace log_line
