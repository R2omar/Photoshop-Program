// File: CS112_A3_Part1_S1_20230255_20230373
// Purpose: this is a program that make some of filters on the image based on the user choice
/* Authors:  omar sayed saied ==> S1
            mahmoud abdelnaby abdalalim ==> S1
*/
/* Emails:
    11410120230255@stud.cu.edu.eg
    11410120230373@stud.cu.edu.eg
*/
// ID1: 20230255 - do {grayscale onversion filter,Dark and light filter,Detect Image Edges,Merge,Purple}
// ID2: 20230373 - do {Black and white filter,inverse filter,flip Horizontal and vertical filter,Resize,Crop,sunlight,infrared}
#include <iostream>
#include "Image_Class.h"
#include<cstring>
#include<string>
#include <cstdlib>
using namespace std;
// Function prototypes for various image Filters functions
Image Grayscale_Conversion(string filename);
Image Black_and_White(string filename);
Image InvertImage(string filename);
Image flip_horizontal(string filename);
Image flip_vertical(string filename);
Image Darken_Image(string filename);
Image light_Image(string filename);
Image resizeImage( string filename, int newWidth, int newHeight);
Image crop_image(string filename);
Image Detect_Image_Edges(string filename);
Image& Merge_Images(string filename1 ,string filename2 );
Image Purple_Image(string filename);
Image sunlight_Image(string filename);
Image infraredImage(string filename);

string loading_image_validation(string image_name,Image image){
    while(true) {           // Loop to handle invalid input for image loading
            try {
                image.loadNewImage(image_name);     // Try to load the image
                if(image.loadNewImage(image_name)) {    // Checking if image loading was successful
                    return image_name;
                }
            }
            catch(const invalid_argument& e) {     // Catching exception if image loading fails
                cout << "Invalid Input. Please enter a valid name for the image : ";     // make user enter a correct input
                cin >> image_name;      // Taking input again
            }
        }
}
 string& saving_image_validation(string& image_name,Image& image){
    while(true) {           // Loop to handle invalid input for image loading
            try {
                if(image.saveImage(image_name)) {    // Checking if image saving was successful
                    return image_name;
                }
            }
            catch(const invalid_argument& e) {     // Catching exception if image saving fails
                cout << "Invalid Input. Please enter a valid name for the image : ";     // make user enter a correct input
                cin >> image_name;      // Taking input again
            }
        }
}

// Function to validate user input choice
int choice_validation(int choice, int limit, istream& cin) {
    while(true) {
        if (cin.fail() || (choice < 1 || choice > limit )) {
            cin.clear();                    // Clearing the error flag
            cin.ignore(INT_MAX, '\n');      // Ignoring any extra characters in the input buffer
            if(limit == 2) {                // Handling different messages based on the limit
                cout << "Invalid Input. Please choose 1 or " << limit << " : ";
                cin >> choice;
            } else {
                cout << "Invalid Input. Please choose from 1 to " << limit << " : ";
                cin >> choice;
            }
        } else {
            cin.ignore();           // Ignoring newline character
            break;
        }
    }
    return choice;
}
// Function to validate user input choice
int crop_validation(int num, int limit, istream& cin) {
    while(true) {
        if (cin.fail() || num > limit ) {
            cin.clear();                    // Clearing the error flag
            cin.ignore(INT_MAX, '\n');      // Ignoring any extra characters in the input buffer
            cout << "Invalid Input.Please Enter Number from 0 to " << limit << " : ";
            cin >> num;
        } else {
            cin.ignore();           // Ignoring newline character
            break;
        }
    }
    return num;
}
int main() {
    string image_name, new_image_name;
    int filter_choice = 0, save_choice = 0;
    cout << "\"Welcome to our Photoshop Program\"\n";   // Displaying welcome message
    cout << "Please enter Your image that you want to Edit it : ";
    cin >> image_name;      // Asking user for the image name
    Image image;            // Creating an object of Image class
    image_name = loading_image_validation(image_name,image);
    image.loadNewImage(image_name);
    while(true) {   // Main loop for the program

        // make user choose a filter
        cout << "What do you want to do?\n";
        cout << "1)Load New Image\n";
        cout << "2)Grayscale Conversion\n";
        cout << "3)Black and White Conversion\n";
        cout << "4)Invert Image\n";
        cout << "5)Flip Image\n";
        cout << "6)Darken and Lighten Image\n";
        cout << "7)Resizing Images\n";
        cout << "8)Crop images\n";
        cout << "9)Detect Image Edges\n";
        cout << "10)Merge Images\n";
        cout << "11)Purple Image\n";
        cout << "12)sunlight Image\n";
        cout << "13)the world in infrared photography Image\n";
        cout << "14)Exit\n";
        cout << "Choose from 1 to 14: ";
        cin >> filter_choice;       // Getting user's filter choice
        filter_choice = choice_validation(filter_choice, 14, cin); // Validating the choice
        if(filter_choice == 1){
            cout << "Please enter Your image that you want to Edit it : ";
            cin >> image_name;      // Asking user for the image name
            Image image;            // Creating an object of Image class
            image_name = loading_image_validation(image_name,image);
            image.loadNewImage(image_name);
        }
        // Handling different filter choices
        else if(filter_choice == 2) {
            // Applying Grayscale Conversion filter
            Image grayscale_Conversion = Grayscale_Conversion(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,grayscale_Conversion);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if (filter_choice == 3) {
            // Applying Black and White Conversion filter
            Image black_and_White = Black_and_White(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,black_and_White);
                 (void)system(new_image_name.c_str());// To show the image without searching for it
            }
        }
        else if(filter_choice == 4) {
            // Invert Image filter
            Image invert_Image = InvertImage(image_name);   // Applying Invert Image filter
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,invert_Image);
              (void)system(new_image_name.c_str());// To show the image without searching for it
            }
        }
        else if (filter_choice == 5){    // Handling RoundImage filters
            int flip_choice = 0;   // Variable to store user's choice for RoundImage type
            cout << "What kind do you want to use?\n";  // Prompting user to choose type of RoundImage
            cout << "1)Flip Horizontally\n";
            cout << "2)Flip Vertically\n";
            cout << "Choose 1 or 2: ";
            cin >> flip_choice;    // Getting user's choice
            flip_choice = choice_validation(flip_choice, 2, cin); // Validating the choice
            if(flip_choice == 1) { // If user chooses RoundImage
                Image round_Image = flip_horizontal(image_name);    // Applying flip horizontal filter
                // Asking user if they want to save the edited image
                cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
                cin >> save_choice;     // Getting user's choice
                save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
                if(save_choice == 1) {  // If user chooses to save
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                    cin >> new_image_name;  // Getting the name for the new image
                   new_image_name = saving_image_validation(new_image_name,round_Image);
                     (void)system(new_image_name.c_str()); // To show the image without searching for it
                }
            }
            else if(flip_choice == 2) {    // If user chooses RoundImage2
                Image round_Image2 = flip_vertical(image_name);  // Applying flip_vertical filter
                // Asking user if they want to save the edited image
                cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
                cin >> save_choice;     // Getting user's choice
                save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
                if(save_choice == 1) {  // If user chooses to save
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                    cin >> new_image_name;  // Getting the name for the new image
                   new_image_name = saving_image_validation(new_image_name,round_Image2);
                  (void)system(new_image_name.c_str());// To show the image without searching for it
                }
            }
        }
        else if (filter_choice == 6) { // Handling Darken and Lighten Image filters
            int kind_choice = 0;    // Variable to store user's choice for Darken or Lighten
            cout << "Do you want Dark or Light?\n";   // Prompting user to choose Dark or Light
            cout << "1)Darken Image\n";
            cout << "2)Lighten Image\n";
            cout << "Choose 1 or 2: ";
            cin >> kind_choice ;    // Getting user's choice
            kind_choice = choice_validation(kind_choice , 2 , cin); // Validating the choice
            if(kind_choice == 1) {  // If user chooses Darken Image
                Image dark = Darken_Image(image_name);  // Applying Darken Image filter
                // Asking user if they want to save the edited image
                cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
                cin >> save_choice;     // Getting user's choice
                save_choice = choice_validation(save_choice , 2 , cin); // Validating the choice
                if(save_choice == 1) {  // If user chooses to save
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                    cin >> new_image_name;  // Getting the name for the new image
                   new_image_name = saving_image_validation(new_image_name,dark);
                  (void)system(new_image_name.c_str());// To show the image without searching for it
                }
            }
            else if ( kind_choice == 2) {  // If user chooses Lighten Image
                Image light = light_Image(image_name);    // Applying Lighten Image filter
                // Asking user if they want to save the edited image
                cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
                cin >> save_choice;     // Getting user's choice
                save_choice = choice_validation(save_choice , 2 , cin); // Validating the choice
                if(save_choice == 1) {  // If user chooses to save
                    cout << "Please enter image name to store new image\n";
                    cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                    cin >> new_image_name;  // Getting the name for the new image
                   new_image_name = saving_image_validation(new_image_name,light);
                  (void)system(new_image_name.c_str()); // To show the image without searching for it
                }
            }
        }
         else if(filter_choice == 7) {
            int w,h;
            cout << "input the new width : ";
            cin >> w;
            cout<< "input the new height : ";
            cin >> h;
            // Applying resize filter
            Image resize_image = resizeImage(image_name, w, h);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,resize_image);
                (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 8) {
            // Applying crop filter
            Image crop = crop_image(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
               new_image_name = saving_image_validation(new_image_name,crop);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 9) {
            // Applying Grayscale Conversion filter
            Image Detect_image = Detect_Image_Edges(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,Detect_image);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 10) {
            string filename2;
            cout << "Please enter The second image that you want to Merge it : ";
            cin >> filename2;
            Image Test;            // Creating an object of Image class
            filename2 = loading_image_validation(filename2,Test); // validate the second image's name
            Image Merge = Merge_Images(image_name,filename2);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,Merge);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 11) {
            // Applying purple filter
            Image Purple = Purple_Image(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,Purple);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 12) {
            // Applying Sunlight filter
            Image sunlight = sunlight_Image(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,sunlight);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 13) {
            // Applying infrared filter
            Image infrared = infraredImage(image_name);
            // Asking user if they want to save the edited image
            cout << "Do you want to save it or not?\n1)Save\n2)Not\nChoose 1 or 2: ";
            cin >> save_choice;     // Getting user's choice
            save_choice = choice_validation(save_choice, 2, cin); // Validating the choice
            if(save_choice == 1) {  // If user chooses to save
                cout << "Please enter image name to store new image\n";
                cout << "and specify extension (.jpg, .bmp, .png, .tga): ";
                cin >> new_image_name;  // Getting the name for the new image
                new_image_name = saving_image_validation(new_image_name,infrared);
              (void)system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if (filter_choice == 14){
            cout << "\"Thank you for using our program\"";
            break;
        }
    }
    return 0;
}
// Function to convert an image to grayscale
Image Grayscale_Conversion(string filename){
    Image Gray(filename);   // Create an image object with the provided filename
    // Loop through each pixel in the image
    for (int i = 0; i < Gray.width; ++i) {
        for (int j = 0; j < Gray.height; ++j) {
            // Calculate the average of the three colors of the pixel
            int avg = (Gray(i, j, 0) + Gray(i, j, 1) + Gray(i, j, 2)) / 3;
            // Set all color channels to the average of the three colors to make the pixel grayscale
            Gray(i, j, 0) = avg;
            Gray(i, j, 1) = avg;
            Gray(i, j, 2) = avg;
        }
    }
    return Gray;    // Return the grayscale image
}

// Function to convert an image to black and white
Image Black_and_White(string filename){
    Image image = Grayscale_Conversion(filename);//convert the image to gray first
    // Convert pixels to either black or white based on average intensity
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (image(i, j, 0) <= 128 && image(i, j, 1) <= 128 && image(i, j, 2) <= 128) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 0; // Set pixel to black
                }
            } else if (image(i, j, 0) > 128 && image(i, j, 1) > 128 && image(i, j, 2) > 128) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255; // Set pixel to white
                }
            }
        }
    }
    return image;   // Return the black and white image
}

// Function to invert colors of an image
Image InvertImage(string filename){
    Image image(filename);  // Create an image object with the provided filename
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Invert each color channel by subtracting its value from 255
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    return image;   // Return the inverted image
}

// Function to mirror an image horizontally
Image flip_horizontal(string filename){
    Image image(filename);  // Create an image object with the provided filename
    Image image2(image.width,image.height);  // Create a new image object to store the mirrored image
    // Check if the width of the image is odd
    if (image.width % 2 == 1){
        // Mirror the image horizontally
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(i, j, k) = image(image.width - i - 1, j, k);
                }
            }
        }
    }
    else {  // If the width of the image is even
        // Mirror the image horizontally
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(i, j, k) = image(image.width - i, j, k);
                }
            }
        }
    }
    return image2;  // Return the horizontally mirrored image
}

// Function to mirror an image vertically
Image flip_vertical(string filename){
    Image image(filename);  // Create an image object with the provided filename
    Image image2(image.width, image.height);  // Create a new image object to store the mirrored image

    // Mirror the image vertically
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2(i, j, k) = image(i, image.height - j - 1, k);
            }
        }
    }

    return image2;  // Return the vertically mirrored image
}

// Function to darken an image
Image Darken_Image(string filename){
    Image Darken(filename);    // Create an image object with the provided filename
    // Loop through each pixel in the image
    for (int i = 0; i < Darken.width; ++i) {
        for (int j = 0; j < Darken.height; ++j) {
            // Reduce the intensity of each color channel by half
            Darken(i,j,0) = .5 * Darken(i,j,0); // Red channel
            Darken(i,j,1) = .5 * Darken(i,j,1); // Green channel
            Darken(i,j,2) = .5 * Darken(i,j,2); // Blue channel
        }
    }
    return Darken;  // Return the darkened image
}

// Function to lighten an image
Image light_Image(string filename){
    Image light(filename); // Create an image object with the provided filename
    // Loop through each pixel in the image
    for (int i = 0; i < light.width; ++i) {
        for (int j = 0; j < light.height; ++j) {
            // Check if multiplying the intensity of each channel by 1.5 exceeds 255
            if(1.5 * light(i,j,0) > 255){
                light(i,j,0) = 255; // If exceeds, set red channel to 255 (maximum value)
            } else {
                light(i,j,0) = 1.5 * light(i,j,0); // Otherwise, multiply by 1.5
            }

            if(1.5 * light(i,j,1) > 255){
                light(i,j,1) = 255; // If exceeds, set green channel to 255 (maximum value)
            } else {
                light(i,j,1) = 1.5 * light(i,j,1); // Otherwise, multiply by 1.5
            }

            if(1.5 * light(i,j,2) > 255){
                light(i,j,2) = 255; // If exceeds, set blue channel to 255 (maximum value)
            } else {
                light(i,j,2) = 1.5 * light(i,j,2); // Otherwise, multiply by 1.5
            }
        }
    }
    return light; // Return the lightened image
}
Image resizeImage( string filename, int newWidth, int newHeight) {
    Image originalImage(filename);

    Image resizedImage(newWidth, newHeight); // Initialized with newWidth and newHeight

    float widthRatio = (float)originalImage.width / newWidth;
    float heightRatio = (float)originalImage.height / newHeight;

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            int originalX = (int)(i * widthRatio);

            int originalY = (int)(j * heightRatio);
            for (int k = 0; k < 3; ++k) {
                resizedImage.setPixel(i, j, k, originalImage.getPixel(originalX, originalY, k));
            }
        }
    }
    return resizedImage;
}
Image crop_image(string filename) {
    Image image(filename);  // Create an image object with the provided filename
    int cropWidth,cropHeight,x,y;
    cout << "input x : ";
    cin >> x;
    x = crop_validation(x,image.width,cin);
    cout<< "input y : ";
    cin >> y;
    y = crop_validation(y,image.height,cin);
    cout << "input the new width : ";
    cin >> cropWidth;
    cropWidth = crop_validation(cropWidth,image.width - x,cin);
    cout<< "input the new height : ";
    cin >> cropHeight;
    cropHeight = crop_validation(cropHeight,image.height - y,cin);
    Image cropped(cropWidth, cropHeight);
    // Copy the specified portion of the image
    for (int i =0 ; i < cropWidth; ++i) {
        for (int j = 0; j < cropHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                cropped(i, j, k) = image(x + i, y + j, k);
            }
        }
    }
    return cropped;  // Return the cropped image
}
Image Detect_Image_Edges(string filename) {
    // Convert the input image to black and white
    Image image = Black_and_White(filename);

    // Create a new image with the same dimensions as the input image
    Image new_image(image.width, image.height);

    // Iterate over each pixel in the image (except the last row and column)
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Set the RGB values of each pixel in the new image to white (255)
            for (int k = 0; k < 3; k++) {
                new_image(i, j, k) = 255;
            }
        }
    }

    // Check for vertical edges between adjacent pixels and modify the new image accordingly
    for (int i = 0; i < image.width - 1; i++) {
        for (int j = 0; j < image.height - 1; j++) {
            for (int k = 0; k < 3; k++) {
                if (image(i, j, k) == 255 && image(i, j + 1, k) == 0) {
                    new_image(i, j + 1, k) = 0;
                } else if (image(i, j, k) == 0 && image(i, j + 1, k) == 255) {
                    new_image(i, j + 1, k) = 0;
                }
            }
        }
    }

    // Check for horizontal edges between adjacent pixels and modify the new image accordingly
    for (int i = 0; i < image.height - 1; i++) {
        for (int j = 0; j < image.width - 1; j++) {
            for (int k = 0; k < 3; k++) {
                if (image(j, i, k) == 255 && image(j + 1, i, k) == 0) {
                    new_image(j + 1, i, k) = 0;
                } else if (image(j, i, k) == 0 && image(j + 1, i, k) == 255) {
                    new_image(j + 1, i, k) = 0;
                }
            }
        }
    }

    // Return the newly created image with detected edges
    return new_image;
}
Image& Merge_Images(string filename1, string filename2) {
    // Load the first and second images from the given filenames
    Image First_Image(filename1);
    Image second_Image(filename2);

    // Check if the dimensions of the two images are different
    if (First_Image.width != second_Image.width && First_Image.height != second_Image.height) {
        int choice;
        // Prompt the user to choose the merging method based on the image dimensions
        cout << "(1) Resize the smaller image or both images to the largest dimensions and then merge\n";
        cout << "(2) Merge the common area of the smaller width and height\n";
        cout << "Choose 1 or 2: ";
        // Read and validate the user's choice
        cin >> choice;
        choice = choice_validation(choice, 2, cin);
        // Apply the chosen merging strategy
        if (choice == 1) {
            // Resize both images to the larger dimensions
            Image First_Image_edit = resizeImage(filename1, max(First_Image.width, second_Image.width), max(First_Image.height, second_Image.height));
            Image second_Image_edit = resizeImage(filename2, max(First_Image.width, second_Image.width), max(First_Image.height, second_Image.height));
            // Create a new image to store the merged result
            static Image New_Image(First_Image_edit.width, First_Image_edit.height);
            // Merge the resized images by averaging pixel values
            for (int i = 0; i < New_Image.width; ++i) {
                for (int j = 0; j < New_Image.height; ++j) {
                    New_Image(i, j, 0) = (First_Image_edit(i, j, 0) + second_Image_edit(i, j, 0)) / 2.0;
                    New_Image(i, j, 1) = (First_Image_edit(i, j, 1) + second_Image_edit(i, j, 1)) / 2.0;
                    New_Image(i, j, 2) = (First_Image_edit(i, j, 2) + second_Image_edit(i, j, 2)) / 2.0;
                }
            }
            // Return the merged image
            return New_Image;
        } else if (choice == 2) {
            // Resize both images to the smaller dimensions
            Image First_Image_edit = resizeImage(filename1, min(First_Image.width, second_Image.width), min(First_Image.height, second_Image.height));
            Image second_Image_edit = resizeImage(filename2, min(First_Image.width, second_Image.width), min(First_Image.height, second_Image.height));
            // Create a new image to store the merged result
            static Image New_Image(First_Image_edit.width, First_Image_edit.height);
            // Merge the resized images by averaging pixel values
            for (int i = 0; i < New_Image.width; ++i) {
                for (int j = 0; j < New_Image.height; ++j) {
                    New_Image(i, j, 0) = (First_Image_edit(i, j, 0) + second_Image_edit(i, j, 0)) / 2.0;
                    New_Image(i, j, 1) = (First_Image_edit(i, j, 1) + second_Image_edit(i, j, 1)) / 2.0;
                    New_Image(i, j, 2) = (First_Image_edit(i, j, 2) + second_Image_edit(i, j, 2)) / 2.0;
                }
            }
            // Return the merged image
            return New_Image;
        }
    }
    // Create a new image to store the merged result with the same dimensions for any one of the two images because this will be excuted in the case of the equality of the dimensions of the two images
    static Image New_Image(First_Image.width, First_Image.height);
    // Merge the original images by averaging pixel values
    for (int i = 0; i < New_Image.width; ++i) {
        for (int j = 0; j < New_Image.height; ++j) {
            New_Image(i, j, 0) = (First_Image(i, j, 0) + second_Image(i, j, 0)) / 2.0;
            New_Image(i, j, 1) = (First_Image(i, j, 1) + second_Image(i, j, 1)) / 2.0;
            New_Image(i, j, 2) = (First_Image(i, j, 2) + second_Image(i, j, 2)) / 2.0;
        }
    }
    // Return the merged image
    return New_Image;
}
Image Purple_Image(string filename) {
    // Load the image from the specified filename
    Image Purple(filename);
    // Iterate over each pixel in the image
    for (int i = 0; i < Purple.width; ++i) {
        for (int j = 0; j < Purple.height; ++j) {
            // Scale the green component of each pixel by multiplying it with 0.7 (70%)
            Purple(i, j, 1) = 0.7 * Purple(i, j, 1);
            // Note: The green channel (index 1) is decreased to enhance the purple color
        }
    }
    // Return the modified image with enhanced purple color
    return Purple;
}
Image sunlight_Image(string filename) {
    // Load the image from the specified filename
    Image sunlight(filename);
    // Iterate over each pixel in the image
    for (int i = 0; i < sunlight.width; ++i) {
        for (int j = 0; j < sunlight.height; ++j) {
            // Scale the blue component of each pixel by multiplying it with 0.7 (70%)
            sunlight(i, j, 2) = 0.7 * sunlight(i, j, 2);
            // Note: The blue channel (index 2) is decreased to enhance the yellow color
        }
    }
    // Return the modified image with enhanced purple color
    return sunlight;
}
Image infraredImage(string filename){
    Image image(filename);  // Create an image object with the provided filename
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Invert each color channel by subtracting its value from 255
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);
        }
    }
    return image;   // Return the inverted image
}


