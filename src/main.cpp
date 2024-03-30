#include "material/cam/hct.h"
#include "material/quantize/celebi.h"
#include "material/scheme/scheme.h"
#include "material/scheme/scheme_tonal_spot.h"
#include "material/score/score.h"
#include "material/utils/utils.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cxxopts.hpp>

auto createARGB(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
	-> unsigned int
{
	return (a << 24) | (r << 16) | (g << 8) | b;
}

void writeScheme(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer,
				 material_color_utilities::SchemeTonalSpot scheme)
{
	writer.StartObject();

	writer.Key("primary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetPrimary())).c_str());

	writer.Key("surfaceTint");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceTint())).c_str());

	writer.Key("onPrimary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnPrimary())).c_str());

	writer.Key("primaryContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetPrimaryContainer()))
			.c_str());

	writer.Key("onPrimaryContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnPrimaryContainer()))
			.c_str());

	writer.Key("secondary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSecondary())).c_str());

	writer.Key("onSecondary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSecondary())).c_str());

	writer.Key("secondaryContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSecondaryContainer()))
			.c_str());

	writer.Key("onSecondaryContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSecondaryContainer()))
			.c_str());

	writer.Key("tertiary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetTertiary())).c_str());

	writer.Key("onTertiary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnTertiary())).c_str());

	writer.Key("onTertiaryContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnTertiaryContainer()))
			.c_str());

	writer.Key("error");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetError())).c_str());

	writer.Key("onError");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnError())).c_str());

	writer.Key("onErrorContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnErrorContainer()))
			.c_str());

	writer.Key("background");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetBackground())).c_str());

	writer.Key("onBackground");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnBackground())).c_str());

	writer.Key("surface");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurface())).c_str());

	writer.Key("onSurface");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSurface())).c_str());

	writer.Key("surfaceVariant");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceVariant()))
			.c_str());

	writer.Key("onSurfaceVariant");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSurfaceVariant()))
			.c_str());

	writer.Key("shadow");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetShadow())).c_str());

	writer.Key("scrim");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetScrim())).c_str());

	writer.Key("inverseSurface");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetInverseSurface()))
			.c_str());

	writer.Key("inverseOnSurface");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetInverseOnSurface()))
			.c_str());

	writer.Key("inversePrimary");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetInversePrimary()))
			.c_str());

	writer.Key("primaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetPrimaryFixed())).c_str());

	writer.Key("onPrimaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnPrimaryFixed()))
			.c_str());

	writer.Key("primaryFixedDim");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetPrimaryFixedDim()))
			.c_str());

	writer.Key("onPrimaryFixedVariant");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnPrimaryFixedVariant()))
			.c_str());

	writer.Key("secondaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSecondaryFixed()))
			.c_str());

	writer.Key("onSecondaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSecondaryFixed()))
			.c_str());

	writer.Key("secondaryFixedDim");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSecondaryFixedDim()))
			.c_str());

	writer.Key("onSecondaryFixedVariant");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnSecondaryFixedVariant()))
			.c_str());

	writer.Key("tertiaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetTertiaryFixed())).c_str());

	writer.Key("onTertiaryFixed");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnTertiaryFixed()))
			.c_str());

	writer.Key("tertiaryFixedDim");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetTertiaryFixedDim()))
			.c_str());

	writer.Key("onTertiaryFixedVariant");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetOnTertiaryFixedVariant()))
			.c_str());

	writer.Key("surfaceDim");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceDim())).c_str());

	writer.Key("surfaceBright");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceBright())).c_str());

	writer.Key("surfaceContainerLowest");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceContainerLowest()))
			.c_str());

	writer.Key("surfaceContainerLow");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceContainerLow()))
			.c_str());

	writer.Key("surfaceContainer");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceContainer()))
			.c_str());

	writer.Key("surfaceContainerHigh");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceContainerHigh()))
			.c_str());

	writer.Key("surfaceContainerHighest");
	writer.String(
		("#" + material_color_utilities::HexFromArgb(scheme.GetSurfaceContainerHighest()))
			.c_str());

	writer.EndObject();
}

auto main(int argc, const char** argv) -> int
{
	std::string input;
	std::string output = "scheme.json";

	cxxopts::Options options("Eclipse Theme Manager",
							 "Generate Material You theme schemes from images");

	options.add_options()("file", "File to generate the scheme from",
						  cxxopts::value<std::string>());

	options.add_options()("o,output", "File to write the scheme to",
						  cxxopts::value<std::string>());

	options.parse_positional({"file"});

	auto result = options.parse(argc, argv);

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

	auto scoreOptions = material_color_utilities::ScoreOptions();
	scoreOptions.desired = 8;

	auto quantized = material_color_utilities::RankedSuggestions(
		material_color_utilities::QuantizeCelebi(pixels, 8).color_to_count, scoreOptions);

	auto lightScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), false, 0.0);

	auto lightMediumScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), false, 0.5);

	auto lightHighScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), false, 1.0);

	auto darkScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), true, 0.0);

	auto darkMediumScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), true, 0.5);

	auto darkHighScheme = material_color_utilities::SchemeTonalSpot(
		material_color_utilities::Hct(quantized[0]), true, 1.0);

	auto outStream = std::ofstream(output);
	rapidjson::StringBuffer buffer;

	auto writer = rapidjson::PrettyWriter<rapidjson::StringBuffer>(buffer);

	writer.StartObject();

	writer.Key("seed");
	writer.String(("#" + material_color_utilities::HexFromArgb(quantized[0])).c_str());

	writer.Key("coreColors");
	writer.StartArray();

	for (auto color : quantized)
	{
		writer.String(("#" + material_color_utilities::HexFromArgb(color)).c_str());
	}

	writer.EndArray();

	writer.Key("schemes");
	writer.StartObject();

	writer.Key("light");
	writeScheme(writer, lightScheme);

	writer.Key("light-medium-contrast");
	writeScheme(writer, lightMediumScheme);

	writer.Key("light-high-contrast");
	writeScheme(writer, lightHighScheme);

	writer.Key("dark");
	writeScheme(writer, darkScheme);

	writer.Key("dark-medium-contrast");
	writeScheme(writer, darkMediumScheme);

	writer.Key("dark-high-contrast");
	writeScheme(writer, darkHighScheme);

	writer.EndObject();

	writer.EndObject();

	outStream << buffer.GetString();

	stbi_image_free(data);

	return 0;
}