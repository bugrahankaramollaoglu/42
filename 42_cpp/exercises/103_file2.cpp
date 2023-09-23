#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct ExchangeRateData
{
	std::string date;
	int exchangeRate;
};

int main()
{
	std::ifstream inputFile("mydata.csv");

	if (!inputFile.is_open())
	{
		std::cerr << "Error: Couldn't open the CSV file." << std::endl;
		return 1; // Exit with an error code
	}

	std::vector<ExchangeRateData> data;

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::stringstream lineStream(line);
		std::string dateStr;
		std::string exchangeRateStr;

		// Read date and exchange rate separated by a tab
		if (std::getline(lineStream, dateStr, '\t') &&
			std::getline(lineStream, exchangeRateStr, '\t'))
		{
			ExchangeRateData entry;
			entry.date = dateStr;
			entry.exchangeRate = std::stoi(exchangeRateStr);
			data.push_back(entry);
		}
	}

	inputFile.close();

	// Now you can work with the parsed CSV-like data in the 'data' vector
	for (const auto &entry : data)
	{
		std::cout << "Date: " << entry.date << ", Exchange Rate: " << entry.exchangeRate << "\n";
	}

}
