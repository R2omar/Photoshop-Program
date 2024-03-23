// A demo for converting image to gray scale

#include <iostream>
using namespace std;
#include "Image_Class.h"

Image Grayscale_Conversion(string filename){
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
    return  image;
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

            // Calculate average

            // Set all channels to the average value

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
            // Initialize average value

            for (int k = 0; k < 3; ++k)
            {
                image2(i, j, 0) = image(image.width-i, j, 0);
                image2(i, j, 1) = image(image.width-i, j, 1);
                image2(i, j, 2) = image(image.width-i, j, 2); // Accumulate pixel values
                image2(image.width-i,j, k)=image(i, j, k);
            }

            // Calculate average

            // Set all channels to the average value

        }
    }
    return image2 ;
 }
Image roundImage2(string filename){
    Image image(filename);
    Image image2(image.width,image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Initialize average value

            for (int k = 0; k < 3; ++k)
            {
                image2(i, j, 0) = image(i, image.height-j, 0);
                image2(i, j, 1) = image(i,image.height- j, 1);
                image2(i, j, 2) = image(i,image.height- j, 2); // Accumulate pixel values
                image2(i,image.height-j, k)=image(i, j, k);
            }

            // Calculate average

            // Set all channels to the average value

        }
    }
    return image2 ;
}
Image blackImage(string filename){
    Image image(filename);
    // Convert to grayscale
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg = static_cast<unsigned int>(static_cast<float>(avg) / 3.0f);
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = avg;
            }
        }
    }
    // Apply threshold to create black and white image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned char color = image(i, j, 0) <= 128 ? 0 : 255;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = color;
            }
        }
    }
    // Create a new image for the border effect
    Image image2(image.width, image.height);
    // Apply border effect
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Check surrounding pixels for border effect
                if ((image(i-1,j,k)==0 && image(i+1,j,k)==255) || (image(i,j-1,k)==0 && image(i,j+1,k)==255)) {
                    image2(i, j, 0) = 0;
                    image2(i, j, 1) = 0;
                    image2(i, j, 2) = 0;
                    break;
                } else {
                    image2(i, j, k) = 255;
                }
            }
        }
    }
    return image2;
}



int main()
{
    string filename,filename1;
    int ch=0,num=0;

    while(true)
    {
        //if(!isValidFilename(filename)){

            cout << "Pls enter colored image name to turn to gray scale: ";
            cin >> filename;
            Image image(filename);
       // }
        cout << "Choose an operation:\n";
        cout << "1. Grayscale Conversion\n";
        cout << "2. Black and White Conversion\n";
        cout << "3. Invert Image\n";
        cout << "4. RoundImage\n";
        cout << "5. BlackImage\n";
        cin>>ch;
        if(ch==1)
        {
            Image grayscale_Conversion=Grayscale_Conversion(filename);
            cout << "you went 1)save or 2)not";
            cin>> num;
            if(num==1){
                num=0;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename1;
                grayscale_Conversion.saveImage(filename1);
            }
            else {
                continue;
            }
            }


        else if (ch==2)
            {

                Image black_and_White=Black_and_White(filename);
                cout << "you went 1)save or 2)not";
                cin>> num;
                if(num==1){
                    num=0;
                    cout << "Pls enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> filename1;
                    black_and_White.saveImage(filename1);
                }
                else {
                    continue;
            }

        }
        else if(ch==3)
            {
                Image invert_Image=InvertImage(filename);
                cout << "you went 1)save or 2)not";
                cin>> num;
                if(num==1){
                    num=0;
                    cout << "Pls enter image name to store new image\n";
                    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                    cin >> filename1;
                    invert_Image.saveImage(filename1);
            }

        }
        else if (ch==4){
            int ch2=0;
            cout << "1.RoundImage\n";
            cout << "2.RoundImage2\n";
            cin>>ch2;
            if(ch2==1){
            Image round_Image=roundImage(filename);
            cout << "you went 1)save or 2)not";
            cin>> num;
            if(num==1){
                num=0;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename1;
                round_Image.saveImage(filename1);
                }}
            else if(ch2==2){
                Image round_Image2=roundImage2(filename);
            cout << "you went 1)save or 2)not";
            cin>> num;
            if(num==1){
                num=0;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename1;
                round_Image2.saveImage(filename1);
            }
            }
          
        }
        else if (ch==5){
            Image black_Image=blackImage(filename);
            cout << "you went 1)save or 2)not";
            cin>> num;
            if(num==1){
                num=0;
                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename1;
                black_Image.saveImage(filename1);
                }
          
        }

    }



    return 0;
}
