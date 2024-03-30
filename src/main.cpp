#include "material/utils/utils.h"
#include <filesystem>
#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cxxopts.hpp>

auto createARGB(unsigned char a, unsigned char r, unsigned char g,
						unsigned char b) -> unsigned int
{
	return (a << 24) | (r << 16) | (g << 8) | b;
}

auto main(int argc, const char** argv) -> int
{
	std::string input;
	std::string output = "scheme.json";
	std::string theme = "dark";

	cxxopts::Options options("Eclipse Theme Manager",
							 "Generate Material You theme schemes from images");

	options.add_options()("t,theme", "Which theme to display on the console",
						  cxxopts::value<std::string>());

	options.add_options()("file", "File to generate the scheme from",
						  cxxopts::value<std::string>());

	options.add_options()("o,output", "File to write the scheme to",
						  cxxopts::value<std::string>());

	auto result = options.parse(argc, argv);

	if (result.count("theme") == 1)
	{
		theme = result["theme"].as<std::string>();
	}

	if (result.count("output") == 1)
	{
		output = std::filesystem::absolute(result["output"].as<std::string>());
	}

	if (result.count("file") == 1)
	{
		input = std::filesystem::absolute(result["file"].as<std::string>());
	}

	int width;
	int height;
	int components;

	auto* data = stbi_load(input.c_str(), &width, &height, &components, 4);

	std::vector<material_color_utilities::Argb> pixels;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// Calculate index for accessing pixel data
			int index = (y * width + x) * 4; // 4 components per pixel

			// Extract RGBA components
			unsigned char r = data[index];
			unsigned char g = data[index + 1];
			unsigned char b = data[index + 2];
			unsigned char a = data[index + 3];

			// Print pixel information
			pixels.push_back(createARGB(a, r, g, b));
		}
	}

	std::cout << pixels.size() << '\n';

	stbi_image_free(data);

	return 0;
}