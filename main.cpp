// parse through list of text files generated from Samsung notes backup (each note is a txt file)
// copy text from each file into one big text file
// maintain original formatting of notes; separate notes by inserting a newline followed by the title of the next note
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

int main()
{
	const std::string output_file = "notes.txt";
	std::ifstream ifs;
	std::ofstream ofs(output_file);

	std::string path = "C:\\Users\\user\\Downloads\\notes-backup";
	for (const auto& file : std::filesystem::directory_iterator(path)) {

		std::string title;
		std::string temp = file.path().filename().string();
		int i = 0;
		while (temp[i] != '_') { // record original names of each file by copying up to the backup-generated _ in the file title
			title += temp[i];
			i++;
		}
		ofs << title << "\n";

		ifs.open(file.path());
		while (!ifs.eof()) {
			std::getline(ifs, temp);
			ofs << temp << "\n";
		}
		ofs << "\n";

		ifs.close();
	}

	ofs.close();

	return 0;
}