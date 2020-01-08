
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
//NUMBER OF INPUT NEURONS
//NUMBER OF OUTPUT NEURONS
//NUMBER OF EXAMPLES
vector <int> change_image_to_data(const sf::Image &im)
{
    vector <int> out;
    int r,g,b;
    for(int y = 0; y <= 28; ++y)
    {
        for(int x = 0; x <=28; ++x)
        {
            r = im.getPixel(x, y).r;
            g = im.getPixel(x, y).g;
            b = im.getPixel(x, y).b;
            if((r+g+b)/3 < 128) out.push_back(0);
            else out.push_back(1);
        }
    }
    return out;
}

int main()
{
    
    
    
    
    string path_to_data = "training1.data";
    string path_to_image = "training/";
    fstream data;
    data.open(path_to_data);
    if(!data.good())
    {
    cout << "Could not open data file";
        return 1;
    }
    data << 784 << "\n";
    data << 10 << "\n";
    data << 5001 << "\n";
    
    sf::Image number_im;
    int image_count = 0;
    vector <int> made_data;
    
    for(int number = 0; number < 10; ++number)
    {
        path_to_image += to_string(number);
        path_to_image += '/';
        for(int file_number = 1; file_number <= 5001; ++file_number)
        {
            path_to_image += to_string(file_number);
            path_to_image += ".png";
            if(number_im.loadFromFile(path_to_image))
            {
                image_count++;
                made_data = change_image_to_data(number_im);
                for(auto &el : made_data){
                    data << el << " ";
                }
            }
            else
            {
                cout << "Couldnt find " << file_number << ".png in folder" << number << endl;
            }
            path_to_image = "training/";
            path_to_image += to_string(number);
            path_to_image += '/';
            data << "\n";
            
        }
        path_to_image = "training/";
        
    }
    cout << "Total amount of images = "  << image_count<< endl;
    return 0;
}


