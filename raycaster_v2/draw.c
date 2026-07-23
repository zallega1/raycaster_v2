#include "draw.h"

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
			letter = loadTexture("textures/hud/a.png");
			break;
		case 'b':
		case 'B':
			letter = loadTexture("textures/hud/b.png");
			break;
		case 'c':
		case 'C':
			letter = loadTexture("textures/hud/c.png");
			break;
		case 'd':
		case 'D':
			letter = loadTexture("textures/hud/d.png");
			break;
		case 'e':
		case 'E':
			letter = loadTexture("textures/hud/e.png");
			break;
		case 'f':
		case 'F':
			letter = loadTexture("textures/hud/f.png");
			break;
		case 'g':
		case 'G':
			letter = loadTexture("textures/hud/g.png");
			break;
		case 'h':
		case 'H':
			letter = loadTexture("textures/hud/h.png");
			break;
		case 'i':
		case 'I':
			letter = loadTexture("textures/hud/i.png");
			break;
		case 'j':
		case 'J':
			letter = loadTexture("textures/hud/j.png");
			break;
		case 'k':
		case 'K':
			letter = loadTexture("textures/hud/k.png");
			break;
		case 'l':
		case 'L':
			letter = loadTexture("textures/hud/l.png");
			break;
		case 'm':
		case 'M':
			letter = loadTexture("textures/hud/m.png");
			break;
		case 'n':
		case 'N':
			letter = loadTexture("textures/hud/n.png");
			break;
		case 'o':
		case 'O':
			letter = loadTexture("textures/hud/o.png");
			break;
		case 'p':
		case 'P':
			letter = loadTexture("textures/hud/p.png");
			break;
		case 'q':
		case 'Q':
			letter = loadTexture("textures/hud/q.png");
			break;
		case 'r':
		case 'R':
			letter = loadTexture("textures/hud/r.png");
			break;
		case 's':
		case 'S':
			letter = loadTexture("textures/hud/s.png");
			break;
		case 't':
		case 'T':
			letter = loadTexture("textures/hud/t.png");
			break;
		case 'u':
		case 'U':
			letter = loadTexture("textures/hud/u.png");
			break;
		case 'v':
		case 'V':
			letter = loadTexture("textures/hud/v.png");
			break;
		case 'w':
		case 'W':
			letter = loadTexture("textures/hud/w.png");
			break;
		case 'x':
		case 'X':
			letter = loadTexture("textures/hud/x.png");
			break;
		case 'y':
		case 'Y':
			letter = loadTexture("textures/hud/y.png");
			break;
		case 'z':
		case 'Z':
			letter = loadTexture("textures/hud/z.png");
			break;
		case '0':
			letter = loadTexture("textures/hud/0.png");
			break;
		case '1':
			letter = loadTexture("textures/hud/1.png");
			break;
		case '2':
			letter = loadTexture("textures/hud/2.png");
			break;
		case '3':
			letter = loadTexture("textures/hud/3.png");
			break;
		case '4':
			letter = loadTexture("textures/hud/4.png");
			break;
		case '5':
			letter = loadTexture("textures/hud/5.png");
			break;
		case '6':
			letter = loadTexture("textures/hud/6.png");
			break;
		case '7':
			letter = loadTexture("textures/hud/7.png");
			break;
		case '8':
			letter = loadTexture("textures/hud/8.png");
			break;
		case '9':
			letter = loadTexture("textures/hud/9.png");
			break;
		case '%':
			letter = loadTexture("textures/hud/percent.png");
			break;
		case ' ':
			letter = loadTexture("textures/hud/null.png");
			break;
		default:
			letter = loadTexture("textures/hud/null.png");
		}
		drawTexRect(letter, 0, 1, 0, 1, x1+xOffset, x2+xOffset, y1, y2);
		xOffset += SCREEN_WIDTH * 0.04167;
	}
}

