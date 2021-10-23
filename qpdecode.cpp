#include <iostream>
#include <string>
#include "QuotedPrintable\QuotedPrintable.hpp"

int main()
{
	for (std::string line; std::getline(std::cin, line); )
	{
		std::string qstring;
		for (int i = 0; i < line.length(); i++) {
			if (strchr("=", line[i]) != NULL) {
				if (strchr("0123456789ABCDEF", line[i+1]) != NULL) {
					if (strchr("0123456789ABCDEF", line[i+2]) != NULL) {
						qstring += line[i];
						qstring += line[i+1];
						qstring += line[i+2];
						i += 2;
					}
					else { std::cout << line[i]; }
				}
				else { std::cout << line[i]; }
			}
			else {
				std::cout << QuotedPrintable::decode(qstring);
				qstring = "";
				std::cout << line[i];
			}
		}
		std::cout << QuotedPrintable::decode(qstring) << std::endl;
	}
}
