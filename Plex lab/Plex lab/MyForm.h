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
		//TPoint *parr;
		TChart *plex;
		//TChart *element;
		int x1, x2, y1, y2;
		bool createNewLineFlag;
		//bool mouseDownFlag;
		TPoint *p1, *p2;
		//int plexCounter;
		//stack<TChart *> *navigation;
		TChart *current;
		TPoint *currentPoint;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public:
	private: System::Windows::Forms::Button^  button1;
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//parr = new TPoint[10];
			plex = new TChart();
			current = plex;
			current->SetActive(true);
			//navigation = new stack<TChart *>();
			//element = new TChart[5];
			createNewLineFlag = false;
			//mouseDownFlag = true;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(3, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1071, 552);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1127, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::button1_KeyPress);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1127, 94);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1127, 156);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1134, 230);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1134, 295);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1434, 557);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
		//mouseDownFlag = true;
		createNewLineFlag = true;
		x1 = x2 = e->X;
		y1 = y2 = e->Y;
	}

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (createNewLineFlag) {
			gr->DrawLine(Pens::White, x1, y1, x2, y2);
			x2 = e->X;
			y2 = e->Y;
			gr->DrawLine(Pens::Gray, x1, y1, x2, y2);
		}
		label1->Text = e->Button.ToString();
	}

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		createNewLineFlag = false;
		gr->DrawLine(Pens::White, x1, y1, x2, y2);
		if ((plex->GetBegin() == nullptr) && (plex->GetEnd() == nullptr)) {
			button1->Text = "OK";
			
			p1 = new TPoint(x1, y1);
			p2 = new TPoint(x2, y2);

			plex->SetBegin(p1);
			plex->SetEnd(p2);

			currentPoint = p1;
			currentPoint->SetActive(true);
		}
		else {
			button1->Text = "NOT OK";

			bool find1 = plex->Find(x1, y1), find2 = plex->Find(x2, y2);

			if (find1 && find2) {
				button2->Text = "BOTH";

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
				button3->Text = "NO ONE";
			}
		}

		plex->Hide(gr);
		plex->Show(gr);
		//mouseDownFlag = false;
	}
	private: System::Void button1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		/*switch (e->KeyChar) {
		case 'q':
			label2->Text = "q";
			if (dynamic_cast<TChart *>(current->GetBegin())) {
				current->SetActive(false);
				navigation->push(current);
				current = dynamic_cast<TChart *>(current->GetBegin());
				current->SetActive(true);
			}
			break;
		case 'w': 
			label2->Text = "w";
			if (!navigation->empty()) {
				current->SetActive(false);
				current = navigation->top();
				navigation->pop();
				current->SetActive(true);
			}
			break;
		case 'e': 
			label2->Text = "e";
			if (dynamic_cast<TChart *>(current->GetEnd())) {
				current->SetActive(false);
				navigation->push(current);
				current = dynamic_cast<TChart *>(current->GetEnd());
				current->SetActive(true);
			}
			break;
		}
		plex->Hide(gr);
		plex->Show(gr);*/
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
		//TPoint *p = plex->FindPoint(e->X, e->Y);
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
