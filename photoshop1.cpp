#include <iostream>
#include "Image_Class.h"
using namespace std;
Image Grayscale_Conversion(string filename);
Image Black_and_White(string filename);
Image InvertImage(string filename);
Image roundImage(string filename);
Image roundImage2(string filename);
Image Darken_Image(string filename);
Image light_Image(string filename);
int choice_validation(int choice , int limit, istream& cin){
        while(true) {
            if (cin.fail() || (choice < 1 || choice > limit )) {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                if(limit == 2){
                   cout << "Invalid Input.Please choose 1 or " << limit << " : ";
                   cin >> choice;
                }
                else{
                cout << "Invalid Input.Please choose from 1 to " << limit << " : ";
                cin >> choice;
                }
            } else {
                cin.ignore();
                break;
            }
        }
        return choice;
}
int main()
{
    string image_name , new_image_name;
    int filter_choice = 0,save_choice = 0;
    cout << "\"Welcome to our Photoshop Program\"\n";
    while(true)
    {
        cout << "Please enter Your image that you want to Edit it : ";
        cin >> image_name;
        Image image;
        while(true){
            try{
                image.loadNewImage(image_name);
                if(image.loadNewImage(image_name)){
                    break;
                }
            }
            catch(const invalid_argument& e){
                cout << "Invalid Input.Please enter : ";
                cin >> image_name;
            }
        }
        cout << "What the Filter that do you want to use ? \n";
        cout << "1)Grayscale Conversion\n";
        cout << "2)Black and White Conversion\n";
        cout << "3)Invert Image\n";
        cout << "4)RoundImage\n";
        cout << "5)Dark and Light\n";
        cout << "Chosse from 1 to 5 : ";

        cin >> filter_choice;
        filter_choice = choice_validation(filter_choice , 5 , cin);
        if(filter_choice == 1)
        {
            Image grayscale_Conversion = Grayscale_Conversion(image_name);
            cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
            cin >> save_choice;
            save_choice = choice_validation(save_choice , 2 , cin);
            if(save_choice == 1){
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> new_image_name;
                grayscale_Conversion.saveImage(new_image_name);
            }
            }
        else if (filter_choice == 2)
            {
                Image black_and_White=Black_and_White(image_name);
                cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
                cin >> save_choice;
                save_choice = choice_validation(save_choice , 2 , cin);
                if( save_choice == 1){
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_image_name;
                    black_and_White.saveImage(new_image_name);
                }
        }
        else if(filter_choice == 3)
            {
                Image invert_Image = InvertImage(image_name);
                cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
                cin >> save_choice;
                save_choice = choice_validation(save_choice , 2 , cin);
                if(save_choice == 1){
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_image_name;
                    invert_Image.saveImage(new_image_name);
            }

        }
        else if (filter_choice == 4){
            int round_choice = 0;
            cout << "What the kind that you want to use ? \n";
            cout << "1)RoundImage\n";
            cout << "2)RoundImage2\n";
            cout << "Choose 1 or 2 : ";
            cin >> round_choice ;
            round_choice = choice_validation(round_choice , 2 , cin);
            if(round_choice == 1){
            Image round_Image = roundImage(image_name);
            cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
            cin >> save_choice;
            save_choice = choice_validation(save_choice , 2 , cin);
            if(save_choice == 1){
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> new_image_name;
                round_Image.saveImage(new_image_name);
                    }
                }
            else if(round_choice == 2){
                Image round_Image2 = roundImage2(image_name);
            cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
            cin >> save_choice;
            save_choice = choice_validation(save_choice , 2 , cin);
            if(save_choice == 1){
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> new_image_name;
                round_Image2.saveImage(new_image_name);
            }
            }

        }
        else if (filter_choice == 5){
            int kind_choice = 0;
            cout << "Do you want Dark or light ? \n";
            cout << "1)Darken Image\n";
            cout << "2)Lighten Image\n";
            cout << "Choose 1 or 2 : ";
            cin >> kind_choice ;
            kind_choice = choice_validation(kind_choice , 2 , cin);
            if(kind_choice == 1){
                Image dark = Darken_Image(image_name);
                cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
                cin >> save_choice;
                save_choice = choice_validation(save_choice , 2 , cin);
                if(save_choice == 1){
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_image_name;
                    dark.saveImage(new_image_name);
                }
            }
            else if ( kind_choice == 2){
                Image light = light_Image(image_name);
                cout << "Do you want to save it or not ?\n1)save\n2)not\nChoose 1 or 2 : ";
                cin >> save_choice;
                save_choice = choice_validation(save_choice , 2 , cin);
                if(save_choice == 1){
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> new_image_name;
                    light.saveImage(new_image_name);
                }
            }
        }


    }
    return 0;
}
Image Grayscale_Conversion(string filename){
    Image Gray(filename);
    for (int i = 0; i < Gray.width; ++i) {
        for (int j = 0; j < Gray.height; ++j) {
            int avg = (Gray(i, j, 0) + Gray(i, j, 1) + Gray(i, j, 2)) / 3;
            Gray(i, j, 0) = avg;
            Gray(i, j, 1) = avg;
            Gray(i, j, 2) = avg;
        }
    }
    return  Gray;
    }
Image Black_and_White(string filename){
    Image image(filename);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j)
            {
                if (image(i, j, 0)<=128 &&image(i, j, 1)<=128&&image(i, j, 2)<=128)
                    {
                        for (int k = 0; k < 3; ++k)
                            {
                                image(i, j, k)=0 ; // Accumulate pixel values
                }
            }
                else if (image(i, j, 0)>128&&image(i, j, 1)>128&&image(i, j, 2)>128)
                    {
                        for (int k = 0; k < 3; ++k)
                            {
                                image(i, j, k)=255 ; // Accumulate pixel values
                        }
                }
            }
    }
    return  image;
}
 Image InvertImage(string filename){
    Image image(filename);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Initialize average value
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, 0) = 255-image(i, j, 0);
                image(i, j, 1) = 255-image(i, j, 1);
                image(i, j, 2) = 255-image(i, j, 2); // Accumulate pixel values
            }
        }
    }
    return image ;
 }
 Image roundImage(string filename){
    Image image(filename);
    Image image2(image.width,image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(i, j, 0) = image(image.width-i, j, 0);
                image2(i, j, 1) = image(image.width-i, j, 1);
                image2(i, j, 2) = image(image.width-i, j, 2); // Accumulate pixel values
                image2(image.width-i,j, k)=image(i, j, k);
            }
        }
    }
    return image2 ;
 }
Image roundImage2(string filename){
    Image image(filename);
    Image image2(image.width, image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(i, j, k) = image( i , image.height - j - 1, k);
            }
        }
    }
    return image2;
}
Image Darken_Image(string filename){
    Image Darken(filename);
    for (int i = 0; i < Darken.width; ++i) {
        for (int j = 0; j < Darken.height; ++j) {
            Darken(i,j,0) = .5 * Darken(i,j,0);
            Darken(i,j,1) =  .5 * Darken(i,j,1);
            Darken(i,j,2) = .5 * Darken(i,j,2);
        }
    }
    return Darken;
}
Image light_Image(string filename){
    Image light(filename);
    for (int i = 0; i < light.width; ++i) {
        for (int j = 0; j < light.height; ++j) {

            if(1.5 * light(i,j,0) > 255){
                light(i,j,0) = 255;
            }
            else{
                 light(i,j,0) = (1.5 * light(i,j,0));
            }
            if(1.5 * light(i,j,1) > 255){
                light(i,j,1) = 255;
            }
            else{
                light(i,j,1) = (1.5 * light(i,j,1));
            }
            if(1.5 * light(i,j,2) > 255){
                light(i,j,2) = 255;
            }
            else {
                light(i,j,2) = (1.5 * light(i,j,2));
            }
        }
    }
    return light;
}
