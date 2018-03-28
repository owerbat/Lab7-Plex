#include "Plex.h";

void TPoint::Show(Graphics ^gr) {
	//gr->DrawEllipse(Pens::Black, x1 - 1, y1 - 1, 2, 2);
	gr->FillEllipse(Brushes::Black, x - 1, y - 1, 2, 2);
}

void TPoint::Hide(Graphics ^gr) {
	//gr->DrawEllipse(Pens::White, x1 - 1, y1 - 1, 2, 2);
	gr->FillEllipse(Brushes::White, x - 1, y - 1, 2, 2);
}

void TPoint::Move(Graphics ^gr, int dx, int dy) {
	Hide(gr);
	x += dx;
	y += dy;
	Show(gr);
}