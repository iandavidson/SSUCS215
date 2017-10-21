#include <cmath>
#include "CGraphicsShape.h"


CGraphicsShape::CGraphicsShape ()
{
	Color = RGB(255, 255, 255);
	WhichShape = 'S';
	CenterX = 100;
	CenterY = 100;
	Size = 40;
    Where = CRect (80, 80, 120, 120);
    Selected = false;
}

CGraphicsShape::CGraphicsShape (COLORREF C, char S, int X, int Y, int Z, CString I)
{
	Color = C;
	WhichShape = S;
	CenterX = X;
	CenterY = Y;
	Size = Z;
    Where = CRect (CenterX-Z/2, CenterY-Z/2, CenterX+Z/2, CenterY+Z/2);
    Selected = false;
	ImageName = I;
}

CRect CGraphicsShape::GetWhere() const
{
    return Where;
}

bool CGraphicsShape::InShape (int x, int y) const
{
	if (WhichShape == 'S')
	{
		//make this 4 clauses
		if (Where.right > x)
		{
			if (x > Where.left)
			{
				if (Where.top < y)
				{
					if (Where.bottom > y)
					{
						return true;
					}
				}
			}
		}
		return false;
    }
    else if (WhichShape == 'C')
    {
		float d;
		d = sqrt((x - CenterX)*(x - CenterX) + (y - CenterY)*(y - CenterY));
		float r = (Where.right - Where.left) / 2;
		if (d <= r) {
			return true;
		}
		return false;
    }
    return false;
}

void CGraphicsShape::SetSelected (bool flag)
{
    Selected = flag;
}

void CGraphicsShape::Resize (int ds)
{
	Size = Size + ds;
	//modify where things to adjust properly
	Where.bottom += ds;
	Where.top -= ds;
	Where.left -= ds;
	Where.right += ds;
}

void CGraphicsShape::Move (int dx, int dy)
{
    Where.left += dx;
    Where.right += dx;
    Where.top += dy;
    Where.bottom += dy;
    CenterX += dx;
    CenterY += dy;
}

void CGraphicsShape::Paint (CPaintDC * dc)
{
	CBrush paintBrush;
	paintBrush.CreateSolidBrush (Color);
	CBrush * pBrushSv = dc->SelectObject (&paintBrush);
    CPen pen, *pPenSv = NULL; //new addition, problem w/ instructions  "=NULL"
    pen.CreatePen(PS_DOT, 1, RGB(0,0,0));
    if (Selected)
        pPenSv = dc->SelectObject (&pen);
    if (WhichShape == 'S')
		dc->Rectangle (Where);
	else if (WhichShape == 'C')
		dc->Ellipse (Where);
	dc->SelectObject (pBrushSv);
    if (Selected)
        dc->SelectObject (pPenSv);
	if (ImageName != "")
	{
		CBitmap Image;
		int res = Image.LoadBitmap(CString(ImageName));
		CDC memDC;
		memDC.CreateCompatibleDC(dc);
		memDC.SelectObject(&Image);
		int tf = dc->TransparentBlt(Where.left + 1, Where.top + 1, Where.Width() - 2, Where.Height() - 2, &memDC,
			0, 0, 80, 80, SRCCOPY);
	}
}