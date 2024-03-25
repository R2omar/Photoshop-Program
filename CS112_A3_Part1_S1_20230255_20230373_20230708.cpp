// File: CS112_A3_Part1_S1_20230255_20230373_20230708
// Purpose: this is a program that make some of filters on the image based on the user choice
/* Authors:  omar sayed saied ==> S1
            mahmoud abdelnaby abdalalim ==> S1
            Khalaf Allah Muzamil Khalaf Allah ==> S1
*/
/* Emails:
    11410120230255@stud.cu.edu.eg
    11410120230373@stud.cu.edu.eg
    11410120230708@stud.cu.edu.eg
*/
// ID1: 20230255 - do {grayscale onversion filter,Dark and light filter}
// ID2: 20230373 – do {Black and white filter,flip Horizontal and vertical filter}
// ID3: 20230708 – do {inverse filter}
#include <iostream>
#include "Image_Class.h"
#include<cstring>
#include<string>
using namespace std;
// Function prototypes for various image Filters functions
Image Grayscale_Conversion(string filename);
Image Black_and_White(string filename);
Image InvertImage(string filename);
Image flip_horizontal(string filename);
Image flip_vertical(string filename);
Image Darken_Image(string filename);
Image light_Image(string filename);

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
int main() {
    string image_name, new_image_name;
    int filter_choice = 0, save_choice = 0;
    cout << "\"Welcome to our Photoshop Program\"\n";   // Displaying welcome message
    while(true) {   // Main loop for the program
        cout << "Please enter Your image that you want to Edit it : ";
        cin >> image_name;      // Asking user for the image name
        Image image;            // Creating an object of Image class
        image_name = loading_image_validation(image_name,image);
        image.loadNewImage(image_name);
        // make user choose a filter
        cout << "What filter do you want to use?\n";
        cout << "1)Grayscale Conversion\n";
        cout << "2)Black and White Conversion\n";
        cout << "3)Invert Image\n";
        cout << "4)Round Image\n";
        cout << "5)Darken and Lighten Image\n";
        cout << "Choose from 1 to 5: ";

        cin >> filter_choice;       // Getting user's filter choice
        filter_choice = choice_validation(filter_choice, 5, cin); // Validating the choice

        // Handling different filter choices
        if(filter_choice == 1) {
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
                grayscale_Conversion.saveImage(new_image_name);    // Saving the edited image
                system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if (filter_choice == 2) {
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
                black_and_White.saveImage(new_image_name);    // Saving the edited image
                system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if(filter_choice == 3) {
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
                invert_Image.saveImage(new_image_name);    // Saving the edited image
                system(new_image_name.c_str()); // To show the image without searching for it
            }
        }
        else if (filter_choice == 4){    // Handling RoundImage filters
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
                    round_Image.saveImage(new_image_name);    // Saving the edited image
                    system(new_image_name.c_str()); // To show the image without searching for it
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
                    round_Image2.saveImage(new_image_name);   // Saving the edited image
                    system(new_image_name.c_str()); // To show the image without searching for it
                }
            }
        }
        else if (filter_choice == 5) { // Handling Darken and Lighten Image filters
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
                    dark.saveImage(new_image_name); // Saving the edited image
                    system(new_image_name.c_str()); // To show the image without searching for it
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
                    light.saveImage(new_image_name);    // Saving the edited image
                    system(new_image_name.c_str()); // To show the image without searching for it
                }
            }
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
    // Check if the height of the image is odd
    if (image.height % 2 == 1){
        // Mirror the image vertically
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(i, j, k) = image(i, image.height - j - 1, k);
                }
            }
        }
    }
    else {  // If the height of the image is even
        // Mirror the image vertically
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(i, j, k) = image(i, image.height - j, k);
                }
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

