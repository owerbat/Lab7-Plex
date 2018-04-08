#include "Plex.h"

void TPoint::Show(Graphics ^gr) {
	//gr->DrawEllipse(Pens::Black, x - 1, y - 1, 2, 2);
	gr->FillEllipse(Brushes::Black, x - 2, y - 2, 5, 5);
}

void TPoint::Hide(Graphics ^gr) {
	//gr->DrawEllipse(Pens::White, x - 1, y - 1, 2, 2);
	gr->FillEllipse(Brushes::White, x - 2, y - 2, 5, 5);
}

void TPoint::Move(Graphics ^gr, int dx, int dy) {
	Hide(gr);
	x += dx;
	y += dy;
	Show(gr);
}




//--------------------------------------------------------------------------------------------------------------------




TChart::TChart(TRoot *pb, TRoot *pe) {
	pBegin = pb;
	pEnd = pe;
}

void TChart::SetBegin(TRoot *pb) {
	TPoint *tp = dynamic_cast<TPoint *>(pb);
	TChart *tc = dynamic_cast<TChart *>(pb);

	if (tp || tc) {
		pBegin = pb;
	}
}

void TChart::SetEnd(TRoot *pe) {
	TPoint *tp = dynamic_cast<TPoint *>(pe);
	TChart *tc = dynamic_cast<TChart *>(pe);

	if (tp || tc) {
		pEnd = pe;
	}
}

TRoot *TChart::Show(Graphics ^gr, TRoot *curr) {
	TPoint *tp, *pb, *pe;
	TChart *tc;

	tp = dynamic_cast<TPoint *>(curr);
	tc = dynamic_cast<TChart *>(curr);

	if (tp) {
		tp->Show(gr);
		return curr;
	}
	if (tc) {
		//pb = dynamic_cast<TPoint *>(tc->pBegin);
		//pe = dynamic_cast<TPoint *>(tc->pEnd);
		pb = dynamic_cast<TPoint *>(Show(gr, tc->pBegin));
		pe = dynamic_cast<TPoint *>(Show(gr, tc->pEnd));

		if (pb && pe) {
			gr->DrawLine(Pens::Black, pb->x, pb->y, pe->x, pe->y);
			return tc->pEnd;
		}
	}
}