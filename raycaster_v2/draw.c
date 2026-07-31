#include "draw.h"

struct Font font;

void loadFont() {
	font.letter[0] = loadTexture("textures/hud/a.png");
	font.letter[1] = loadTexture("textures/hud/b.png");
	font.letter[2] = loadTexture("textures/hud/c.png");
	font.letter[3] = loadTexture("textures/hud/d.png");
	font.letter[4] = loadTexture("textures/hud/e.png");
	font.letter[5] = loadTexture("textures/hud/f.png");
	font.letter[6] = loadTexture("textures/hud/g.png");
	font.letter[7] = loadTexture("textures/hud/h.png");
	font.letter[8] = loadTexture("textures/hud/i.png");
	font.letter[9] = loadTexture("textures/hud/j.png");
	font.letter[10] = loadTexture("textures/hud/k.png");
	font.letter[11] = loadTexture("textures/hud/l.png");
	font.letter[12] = loadTexture("textures/hud/m.png");
	font.letter[13] = loadTexture("textures/hud/n.png");
	font.letter[14] = loadTexture("textures/hud/o.png");
	font.letter[15] = loadTexture("textures/hud/p.png");
	font.letter[16] = loadTexture("textures/hud/q.png");
	font.letter[17] = loadTexture("textures/hud/r.png");
	font.letter[18] = loadTexture("textures/hud/s.png");
	font.letter[19] = loadTexture("textures/hud/t.png");
	font.letter[20] = loadTexture("textures/hud/u.png");
	font.letter[21] = loadTexture("textures/hud/v.png");
	font.letter[22] = loadTexture("textures/hud/w.png");
	font.letter[23] = loadTexture("textures/hud/x.png");
	font.letter[24] = loadTexture("textures/hud/y.png");
	font.letter[25] = loadTexture("textures/hud/z.png");
	font.num[0] = loadTexture("textures/hud/0.png");
	font.num[1] = loadTexture("textures/hud/1.png");
	font.num[2] = loadTexture("textures/hud/2.png");
	font.num[3] = loadTexture("textures/hud/3.png");
	font.num[4] = loadTexture("textures/hud/4.png");
	font.num[5] = loadTexture("textures/hud/5.png");
	font.num[6] = loadTexture("textures/hud/6.png");
	font.num[7] = loadTexture("textures/hud/7.png");
	font.num[8] = loadTexture("textures/hud/8.png");
	font.num[9] = loadTexture("textures/hud/9.png");
	font.space = loadTexture("textures/hud/null.png");
	font.symbol = loadTexture("textures/hud/percent.png");
}

void drawRect(int x1, int x2, int y1, int y2) {
	glBegin(GL_QUADS);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glVertex2i(x1, y2);
	glEnd();
}

void drawTexRect(GLuint tex, float texCoordx1, float texCoordx2, float texCoordy1, float texCoordy2, int x1, int x2, int y1, int y2) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);

	glBegin(GL_QUADS);
	glTexCoord2f(texCoordx1, texCoordy2); glVertex2f(x1, y2);
	glTexCoord2f(texCoordx2, texCoordy2); glVertex2f(x2, y2);
	glTexCoord2f(texCoordx2, texCoordy1); glVertex2f(x2, y1);
	glTexCoord2f(texCoordx1, texCoordy1); glVertex2f(x1, y1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void drawText(char text[], int x1, int x2, int y1, int y2) {
	GLuint letter; 
	int xOffset = 0; //spacing between characters

	//iterate through string, switch cases determine letter/number/symbol;
	for (int i = 0; i < strlen(text); i++) {
		switch (text[i]) {
		case 'a':
		case 'A':
			letter = font.letter[0];
			break;
		case 'b':
		case 'B':
			letter = font.letter[1];
			break;
		case 'c':
		case 'C':
			letter = font.letter[2];
			break;
		case 'd':
		case 'D':
			letter = font.letter[3];
			break;
		case 'e':
		case 'E':
			letter = font.letter[4];
			break;
		case 'f':
		case 'F':
			letter = font.letter[5];
			break;
		case 'g':
		case 'G':
			letter = font.letter[6];
			break;
		case 'h':
		case 'H':
			letter = font.letter[7];
			break;
		case 'i':
		case 'I':
			letter = font.letter[8];
			break;
		case 'j':
		case 'J':
			letter = font.letter[9];
			break;
		case 'k':
		case 'K':
			letter = font.letter[10];
			break;
		case 'l':
		case 'L':
			letter = font.letter[11];
			break;
		case 'm':
		case 'M':
			letter = font.letter[12];
			break;
		case 'n':
		case 'N':
			letter = font.letter[13];
			break;
		case 'o':
		case 'O':
			letter = font.letter[14];
			break;
		case 'p':
		case 'P':
			letter = font.letter[15];
			break;
		case 'q':
		case 'Q':
			letter = font.letter[16];
			break;
		case 'r':
		case 'R':
			letter = font.letter[17];
			break;
		case 's':
		case 'S':
			letter = font.letter[18];
			break;
		case 't':
		case 'T':
			letter = font.letter[19];
			break;
		case 'u':
		case 'U':
			letter = font.letter[20];
			break;
		case 'v':
		case 'V':
			letter = font.letter[21];
			break;
		case 'w':
		case 'W':
			letter = font.letter[22];
			break;
		case 'x':
		case 'X':
			letter = font.letter[23];
			break;
		case 'y':
		case 'Y':
			letter = font.letter[24];
			break;
		case 'z':
		case 'Z':
			letter = font.letter[25];
			break;
		case '0':
			letter = font.num[0];
			break;
		case '1':
			letter = font.num[1];
			break;
		case '2':
			letter = font.num[2];
			break;
		case '3':
			letter = font.num[3];
			break;
		case '4':
			letter = font.num[4];
			break;
		case '5':
			letter = font.num[5];
			break;
		case '6':
			letter = font.num[6];
			break;
		case '7':
			letter = font.num[7];
			break;
		case '8':
			letter = font.num[8];
			break;
		case '9':
			letter = font.num[9];
			break;
		case '%':
			letter = font.symbol;
			break;
		case ' ':
			letter = font.space;
			break;
		default:
			letter = font.space;
		}
		drawTexRect(letter, 0, 1, 0, 1, x1+xOffset, x2+xOffset, y1, y2);
		xOffset += SCREEN_WIDTH * 0.04167;
	}
}

