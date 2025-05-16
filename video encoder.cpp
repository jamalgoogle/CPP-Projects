#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void encodedVideo(const string &inputPath, const string &outputPath, int resolution)
{
   string scale;
   switch (resolution)
   {
   case 1080:
      scale = "1920x1080";
      break;
   case 720:
      scale = "1280x720";
      break;
   case 480:
      scale = "854x480";
      break;
   case 360:
      scale = "640x360";
      break;
   default:
      cerr << "Invalid resolution" << endl;
      return;
   }

   string command = "ffmpeg -i " + inputPath + " -vf scale=" + scale + " -c:v libx264 -crf 23 -preset fast" + outputPath + " \" ";
   cout << "Running : " << command << endl;

   int result = system(command.c_str());
   if (result == 0)
   {
      cout << "Video encoded successfully" << endl;
   }
   else
   {
      cerr << "Failed to encode video" << endl;
   }
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      cerr << "Usage: " << argv[0] << " <input_video_path> <output_video_path> <resolution>" << endl;
      cerr << "Examble: ./videoEncoder.exe input.mp4 output.mp4 720" << endl;
      return 1;

      string input = argv[1]; 
      string output = argv[2];
      int resolution = atoi(argv[3]);

      encodedVideo(input, output, resolution);
      return 0;
   }
}