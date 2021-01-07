Program implements filter that is able to add various visual effects on images.

Used libraries:
* STB - for image loading/saving
* boost::program_options - for input arguments handling

Supported image formats:
* jpeg
* png
* bmp
* tga

Supported visual effects:
* blur

Part of the 'pic_convolving_website' project: https://github.com/gwolan/pic_convolving_website


ERROR RETURN CODES:
* 1 = invalid arguments
* 2 = unable to load image
* 3 - unable to save image
