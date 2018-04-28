#pragma once
#include "Plex.h"

namespace Plex_lab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		Graphics ^gr;
		TChart *plex;
		int x1, x2, y1, y2;
		bool createNewLineFlag;
		TPoint *p1, *p2;
		TChart *current;
		TPoint *currentPoint;





	public:

	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			plex = new TChart();
			current = plex;
			current->SetActive(true);
			createNewLineFlag = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(3, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1087, 556);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1091, 557);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		plex->Show(gr);
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		gr = pictureBox1->CreateGraphics();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		plex->Hide(gr);
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		plex->Move(gr, 10, 10);
	}

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		createNewLineFlag = true;
		x1 = x2 = e->X;
		y1 = y2 = e->Y;
	}

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button.ToString() == "Left") {
			if (createNewLineFlag) {
				gr->DrawLine(Pens::White, x1, y1, x2, y2);
				x2 = e->X;
				y2 = e->Y;
				gr->DrawLine(Pens::Gray, x1, y1, x2, y2);
			}
		}

		if (e->Button.ToString() == "Right") {
			TPoint *tmp = plex->FindPoint(e->X, e->Y);
			if (tmp && tmp->GetActive()) {
				plex->Hide(gr);
				tmp->x = e->X;
				tmp->y = e->Y;
				plex->Show(gr);
			}
		}

		//label1->Text = e->Button.ToString();
	}

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		createNewLineFlag = false;
		gr->DrawLine(Pens::White, x1, y1, x2, y2);
		if ((plex->GetBegin() == nullptr) && (plex->GetEnd() == nullptr)) {
			//button1->Text = "OK";
			
			p1 = new TPoint(x1, y1);
			p2 = new TPoint(x2, y2);

			plex->SetBegin(p1);
			plex->SetEnd(p2);

			currentPoint = p1;
			currentPoint->SetActive(true);
		}
		else {
			//button1->Text = "NOT OK";

			bool find1 = plex->Find(x1, y1), find2 = plex->Find(x2, y2);

			if (find1 && find2) {
				//button2->Text = "BOTH";

				p1 = plex->FindPoint(x1, y1);
				p2 = plex->FindPoint(x2, y2);

				TChart *tmp = new TChart();
				TPoint *tmp1 = (TPoint *)(plex->findRes->GetBegin());
				TPoint *tmp2 = (TPoint *)(plex->findRes->GetEnd());

				if (plex->findFlag) {
					if ((p1->x == tmp1->x) && (p1->y == tmp1->y)) {
						tmp->SetEnd(p1);
						tmp->SetBegin(p2);
					}
					else if ((p2->x == tmp1->x) && (p2->y == tmp1->y)) {
						tmp->SetEnd(p2);
						tmp->SetBegin(p1);
					}
					plex->findRes->SetBegin(tmp);
				}
				else {
					if ((p1->x == tmp2->x) && (p1->y == tmp2->y)) {
						tmp->SetEnd(p1);
						tmp->SetBegin(p2);
					}
					else if ((p2->x == tmp2->x) && (p2->y == tmp2->y)) {
						tmp->SetEnd(p2);
						tmp->SetBegin(p1);
					}
					plex->findRes->SetEnd(tmp);
				}
			}
			else if (find1 && !find2) {
				p2 = new TPoint(x2, y2);

				if (plex->findFlag) {
					p1 = (TPoint *) plex->findRes->GetBegin();
				}
				else {
					p1 = (TPoint *) plex->findRes->GetEnd();
				}

				TChart *tmp = new TChart();
				tmp->SetBegin(p2);
				tmp->SetEnd(p1);

				if (plex->findFlag) {
					plex->findRes->SetBegin(tmp);
				}
				else { 
					plex->findRes->SetEnd(tmp); 
				}
			}
			else if (!find1 && find2) {
				p1 = new TPoint(x1, y1);

				if (plex->findFlag) {
					p2 = (TPoint *)plex->findRes->GetBegin();
				}
				else {
					p2 = (TPoint *)plex->findRes->GetEnd();
				}

				TChart *tmp = new TChart();
				tmp->SetBegin(p1);
				tmp->SetEnd(p2);

				if (plex->findFlag) {
					plex->findRes->SetBegin(tmp);
				}
				else {
					plex->findRes->SetEnd(tmp);
				}
			}
			else {
				//button3->Text = "NO ONE";
			}
		}

		plex->Hide(gr);
		plex->Show(gr);
	}
	
	private: System::Void pictureBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		TChart *tmp = plex->Hit(e->X, e->Y);
		if (tmp != nullptr) {
			if (e->Button.ToString() == "Left") {
				current->SetActive(false);
				current = tmp;
				current->SetActive(true);
			}
			if (e->Button.ToString() == "Right") {
				tmp->SetVisible(false);
			}
		}

		TPoint *p = plex->HitPoint(e->X, e->Y);
		if (p != nullptr) {
			if (e->Button.ToString() == "Left") {
				currentPoint->SetActive(false);
				currentPoint = p;
				currentPoint->SetActive(true);
			}
			if (e->Button.ToString() == "Right") {
				p->SetVisible(false);
			}
		}

		plex->Hide(gr);
		plex->Show(gr);
	}
};
}
