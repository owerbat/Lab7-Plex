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
		pb = dynamic_cast<TPoint *>(Show(gr, tc->pBegin));
		pe = dynamic_cast<TPoint *>(Show(gr, tc->pEnd));

		if (pb && pe) {
			gr->DrawLine(Pens::Black, pb->x, pb->y, pe->x, pe->y);
			return tc->pEnd;
		}
	}
	return nullptr;
}

TRoot *TChart::Hide(Graphics ^gr, TRoot *curr) {
	TPoint *tp, *pb, *pe;
	TChart *tc;

	tp = dynamic_cast<TPoint *>(curr);
	tc = dynamic_cast<TChart *>(curr);

	if (tp) {
		tp->Hide(gr);
		return curr;
	}
	if (tc) {
		pb = dynamic_cast<TPoint *>(Hide(gr, tc->pBegin));
		pe = dynamic_cast<TPoint *>(Hide(gr, tc->pEnd));

		if (pb && pe) {
			gr->DrawLine(Pens::White, pb->x, pb->y, pe->x, pe->y);
			return tc->pEnd;
		}
	}
	return nullptr;
}

void TChart::Show(Graphics ^gr) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			gr->DrawLine(Pens::Black, curr.pb->x, curr.pb->y, curr.pe->x, curr.pe->y);
			gr->FillEllipse(Brushes::Black, curr.pb->x - 2, curr.pb->y - 2, 5, 5);
			gr->FillEllipse(Brushes::Black, curr.pe->x - 2, curr.pe->y - 2, 5, 5);

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
}

void TChart::Hide(Graphics ^gr) {
	TCurrLine curr;
	TPoint *tmp;

	curr.tc = this;
	curr.pb = curr.pe = nullptr;

	while (!st.empty()) {
		st.pop();
	}
	st.push(curr);

	while (!st.empty()) {
		curr = st.top();
		st.pop();

		while (!curr.pb) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pBegin);
			if (tmp) {
				curr.pb = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pBegin;
			}
		}

		if (!curr.pe) {
			tmp = dynamic_cast<TPoint *>(curr.tc->pEnd);
			if (tmp) {
				curr.pe = tmp;
			}
			else {
				st.push(curr);
				curr.tc = (TChart *)curr.tc->pEnd;
				curr.pb = nullptr;
				st.push(curr);
			}
		}

		if (curr.pb && curr.pe) {
			gr->DrawLine(Pens::White, curr.pb->x, curr.pb->y, curr.pe->x, curr.pe->y);
			gr->FillEllipse(Brushes::White, curr.pb->x - 2, curr.pb->y - 2, 5, 5);
			gr->FillEllipse(Brushes::White, curr.pe->x - 2, curr.pe->y - 2, 5, 5);

			tmp = curr.pe;

			if (!st.empty()) {
				curr = st.top();
				st.pop();

				if (!curr.pb) {
					curr.pb = tmp;
				}
				else {
					curr.pe = tmp;
				}

				st.push(curr);
			}
		}
	}
}

void TChart::Move(Graphics ^gr, int dx, int dy) {
	Hide(gr);

	pBegin->Move(gr, dx, dy);
	pEnd->Move(gr, dx, dy);

	Show(gr);
}