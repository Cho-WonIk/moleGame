#include "Util.h"

int random() // 1~9사이의 랜덤한 수를 만든다.
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}

void glBitmapText(float x, float y, float z, std::string text, void* font) // string을 비트맵형식으로 바꾸어 출력해준다.
{
	
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}

std::string ZeroFill_Number(GLint Number, int length) // length길이로 제로 패딩한 숫자를 반환하다.
{
	std::string text = std::to_string(Number);
	int len = text.length();
	for (int i = 0; i < length - len; i++)
	{
		text.insert(0, "0");
	}
	return text;
}

void Textureinit(void)
{
    glShadeModel(GL_SMOOTH);       // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(MAX_NO_TEXTURES, texture);

    AUX_RGBImageRec* TextureImage[MAX_NO_TEXTURES];     // Create Storage Space For The Texture

    memset(TextureImage, 0, sizeof(void*) * MAX_NO_TEXTURES);            // Set The Pointer To NULL



    // if ((TextureImage[0] = LoadBMP("삼성 4-1 SLIDE(2)_00001.bmp")) &&
    //  (TextureImage[1] = LoadBMP("삼성 4-1 SLIDE(2)_00002.bmp")))   //이미지 로딩
    TextureImage[0]->AUX_RGBImageRec::loadFile("삼성 4-1 SLIDE(2)_00001.bmp");
    TextureImage[1]->AUX_RGBImageRec::loadFile("삼성 4-1 SLIDE(2)_00002.bmp");


    {
        glGenTextures(MAX_NO_TEXTURES, texture);     //텍스쳐 생성

        //텍스쳐에 이미지 1 넣기
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
        //텍스쳐에 이미지 2 넣기
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        // glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);

    }
    //////////////////////////
    glEnable(GL_CULL_FACE);
    // glEnable(GL_DEPTH_TEST);
}