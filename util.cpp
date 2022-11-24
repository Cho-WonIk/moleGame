#include "Util.h"

int random() // 1~9������ ������ ���� �����.
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}

void glBitmapText(float x, float y, float z, std::string text, void* font) // string�� ��Ʈ���������� �ٲپ� ������ش�.
{
	
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}

std::string ZeroFill_Number(GLint Number, int length) // length���̷� ���� �е��� ���ڸ� ��ȯ�ϴ�.
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



    // if ((TextureImage[0] = LoadBMP("�Ｚ 4-1 SLIDE(2)_00001.bmp")) &&
    //  (TextureImage[1] = LoadBMP("�Ｚ 4-1 SLIDE(2)_00002.bmp")))   //�̹��� �ε�
    TextureImage[0]->AUX_RGBImageRec::loadFile("�Ｚ 4-1 SLIDE(2)_00001.bmp");
    TextureImage[1]->AUX_RGBImageRec::loadFile("�Ｚ 4-1 SLIDE(2)_00002.bmp");


    {
        glGenTextures(MAX_NO_TEXTURES, texture);     //�ؽ��� ����

        //�ؽ��Ŀ� �̹��� 1 �ֱ�
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
        //�ؽ��Ŀ� �̹��� 2 �ֱ�
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