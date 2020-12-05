#pragma once

class Block
{
	protected:
		int paddingX, paddingY; //定义方块参考点（左上）与绝对坐标原点的距离
		const int a = 20; //定义每个小正方形的边长
		
	public:
		Block()
		{
			paddingX = 100;
			paddingY = 100;
		}

		virtual ~Block() { }

		virtual void SetBlock(HDC hdc, int type) = 0;

		int changeType(int type)
		{
			type = (type == 4) ? type - 3 : type + 1;
			return type;
		}
		
		void falldown()
		{
			paddingY = paddingY + 20;
		}

		void toLeft()
		{
			paddingX = paddingX - 20;
		}

		void toRight()
		{
			paddingX = paddingX + 20;
		}

		void toDown()
		{
			paddingY = paddingY + 20;
		}

		void toPause()
		{
			paddingY = paddingY;
		}
};

class Block_O : public Block
{
	public:
		Block_O() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
			Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
			Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
			Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
		}
};

class Block_I : public Block
{
	public:
		Block_I() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1 || type == 3)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 3, paddingX + a + 1, paddingY + a * 4 + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 3, paddingY, paddingX + a * 4 + 1, paddingY + a + 1);
			}
		}
};

class Block_S : public Block
{
	public:
		Block_S() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1 || type == 3)
			{
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a * 2, paddingX + a * 2 + 1, paddingY + a * 3 + 1);
			}
		}
};

class Block_Z : public Block
{
	public:
		Block_Z() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1 || type == 3)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY + a, paddingX + a * 3 + 1, paddingY + a * 2 + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
			}
		}
};

class Block_T : public Block
{
	public:
		Block_T() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
			}
			else if(type == 2)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
			}
			else if (type == 3)
			{
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY + a, paddingX + a * 3 + 1, paddingY + a * 2 + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a * 2, paddingX + a * 2 + 1, paddingY + a * 3 + 1);
			}
		}
};

class Block_J : public Block
{
	public:
		Block_J() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1)
			{
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a * 2, paddingX + a * 2 + 1, paddingY + a * 3 + 1);
			}
			else if (type == 2)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY + a, paddingX + a * 3 + 1, paddingY + a * 2 + 1);
			}
			else if (type == 3)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY + a, paddingX + a * 3 + 1, paddingY + a * 2 + 1);
			}
		}
};

class Block_L : public Block
{
	public:
		Block_L() : Block() { }

		void SetBlock(HDC hdc, int type)
		{
			if (type == 1)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX, paddingY + a * 2, paddingX + a + 1, paddingY + a * 3 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a * 2, paddingX + a * 2 + 1, paddingY + a * 3 + 1);
			}
			else if (type == 2)
			{
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY + a, paddingX + a * 3 + 1, paddingY + a * 2 + 1);
			}
			else if (type == 3)
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY + a, paddingX + a * 2 + 1, paddingY + a * 2 + 1);
				Rectangle(hdc, paddingX + a, paddingY + a * 2, paddingX + a * 2 + 1, paddingY + a * 3 + 1);
			}
			else
			{
				Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a, paddingY, paddingX + a * 2 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX + a * 2, paddingY, paddingX + a * 3 + 1, paddingY + a + 1);
				Rectangle(hdc, paddingX, paddingY + a, paddingX + a + 1, paddingY + a * 2 + 1);
			}
		}
};

////绘制一个正方形（POINT* + Polygon()）
//POINT point[4] = { {paddingX, paddingY}, {paddingX, paddingY + a}, {paddingX + a, paddingY + a}, {paddingX + a, paddingY} };
////<==>
////point[0].x = paddingX; point[0].y = paddingY;
////point[1].x = paddingX; point[1].y = paddingY + a;
////point[2].x = paddingX + a; point[2].y = paddingY + a;
////point[3].x = paddingX + a; point[3].y = paddingY;
//Polygon(hdc, point, 4);

//绘制一个正方形（Rectangle()）
//Rectangle(hdc, paddingX, paddingY, paddingX + a + 1, paddingY + a + 1);

////绘制一个正方形（RECT* + FrameRect()）
//HBRUSH hbr;
//hbr = CreateSolidBrush(RGB(0, 0, 0));
//RECT rect[1] = {paddingX, paddingY, paddingX + a + 1, paddingY + a + 1};
//<==>
//rect[0].left = paddingX; rect[0].top = paddingY; rect[0].right = paddingX + a + 1; rect[0].bottom = paddingY + a + 1;
//FrameRect(hdc, rect, hbr);

void DrawBlock(HDC hdc, Block *block, int type)
{
	HGDIOBJ oldbrush;
	HBRUSH hbr;
	hbr = CreateSolidBrush(RGB(129, 216, 207));
	oldbrush = SelectObject(hdc, (HBRUSH)(hbr));
	
	block->SetBlock(hdc, type);

	SelectObject(hdc, oldbrush);
	DeleteObject(hbr);
}