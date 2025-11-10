#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, double> country_area;
    country_area["Spain"] = 758686;
    country_area["UK"] = 8464547;
    country_area["Germany"] = 86769504;
    country_area["Portugal"] = 857654;
    country_area["Italy"] = 987065;
    double total = 0;
    for (std::map<std::string, double>::iterator mIt = country_area.begin(); mIt != country_area.end(); ++mIt) {
        total += mIt->second;
    }
    std::cout << "Total area: " << total << std::endl;
    return 0;
}
