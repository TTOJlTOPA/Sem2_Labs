#include "Circle.h"
#include "Rectangle.h"
#pragma once

Circle circ(620, 340, 620, 380);
Rectangles rectan(580, 300, 660, 380);
bool cflag = false, rflag = false, cActive = false, rActive = false;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Sem_Lab6WF {
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = this->pictureBox1->CreateGraphics();
			//
			//TODO: Add the constructor code here
			//
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

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ôèãóğûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  êğóãToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïğÿìîóãîëüíèêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  î÷èñòèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïëîùàäüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  êğóãToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ïğÿìîóãîëüíèêToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ïåğèìåòğToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  êğóãToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  ïğÿìîóãîëüíèêToolStripMenuItem2;
	protected:

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôèãóğûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êğóãToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğÿìîóãîëüíèêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èñòèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïëîùàäüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êğóãToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğÿìîóãîëüíèêToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïåğèìåòğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êğóãToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğÿìîóãîëüíèêToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(12, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1229, 679);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseUp += gcnew MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			this->pictureBox1->MouseMove += gcnew MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->Paint += gcnew PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôèãóğûToolStripMenuItem,
					this->ïëîùàäüToolStripMenuItem, this->ïåğèìåòğToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1253, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôèãóğûToolStripMenuItem
			// 
			this->ôèãóğûToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->êğóãToolStripMenuItem,
					this->ïğÿìîóãîëüíèêToolStripMenuItem, this->î÷èñòèòüToolStripMenuItem
			});
			this->ôèãóğûToolStripMenuItem->Name = L"ôèãóğûToolStripMenuItem";
			this->ôèãóğûToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->ôèãóğûToolStripMenuItem->Text = L"Ôèãóğû";
			// 
			// êğóãToolStripMenuItem
			// 
			this->êğóãToolStripMenuItem->Name = L"êğóãToolStripMenuItem";
			this->êğóãToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->êğóãToolStripMenuItem->Text = L"Êğóã";
			this->êğóãToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::êğóãToolStripMenuItem_Click);
			// 
			// ïğÿìîóãîëüíèêToolStripMenuItem
			// 
			this->ïğÿìîóãîëüíèêToolStripMenuItem->Name = L"ïğÿìîóãîëüíèêToolStripMenuItem";
			this->ïğÿìîóãîëüíèêToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->ïğÿìîóãîëüíèêToolStripMenuItem->Text = L"Ïğÿìîóãîëüíèê";
			this->ïğÿìîóãîëüíèêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïğÿìîóãîëüíèêToolStripMenuItem_Click);
			// 
			// î÷èñòèòüToolStripMenuItem
			// 
			this->î÷èñòèòüToolStripMenuItem->Name = L"î÷èñòèòüToolStripMenuItem";
			this->î÷èñòèòüToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->î÷èñòèòüToolStripMenuItem->Text = L"Î÷èñòèòü";
			this->î÷èñòèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::î÷èñòèòüToolStripMenuItem_Click);
			// 
			// ïëîùàäüToolStripMenuItem
			// 
			this->ïëîùàäüToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->êğóãToolStripMenuItem1,
					this->ïğÿìîóãîëüíèêToolStripMenuItem1
			});
			this->ïëîùàäüToolStripMenuItem->Name = L"ïëîùàäüToolStripMenuItem";
			this->ïëîùàäüToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->ïëîùàäüToolStripMenuItem->Text = L"Ïëîùàäü";
			// 
			// êğóãToolStripMenuItem1
			// 
			this->êğóãToolStripMenuItem1->Name = L"êğóãToolStripMenuItem1";
			this->êğóãToolStripMenuItem1->Size = System::Drawing::Size(163, 22);
			this->êğóãToolStripMenuItem1->Text = L"Êğóã";
			this->êğóãToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::êğóãToolStripMenuItem1_Click);
			// 
			// ïğÿìîóãîëüíèêToolStripMenuItem1
			// 
			this->ïğÿìîóãîëüíèêToolStripMenuItem1->Name = L"ïğÿìîóãîëüíèêToolStripMenuItem1";
			this->ïğÿìîóãîëüíèêToolStripMenuItem1->Size = System::Drawing::Size(163, 22);
			this->ïğÿìîóãîëüíèêToolStripMenuItem1->Text = L"Ïğÿìîóãîëüíèê";
			this->ïğÿìîóãîëüíèêToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::ïğÿìîóãîëüíèêToolStripMenuItem1_Click);
			// 
			// ïåğèìåòğToolStripMenuItem
			// 
			this->ïåğèìåòğToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->êğóãToolStripMenuItem2,
					this->ïğÿìîóãîëüíèêToolStripMenuItem2
			});
			this->ïåğèìåòğToolStripMenuItem->Name = L"ïåğèìåòğToolStripMenuItem";
			this->ïåğèìåòğToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->ïåğèìåòğToolStripMenuItem->Text = L"Ïåğèìåòğ";
			// 
			// êğóãToolStripMenuItem2
			// 
			this->êğóãToolStripMenuItem2->Name = L"êğóãToolStripMenuItem2";
			this->êğóãToolStripMenuItem2->Size = System::Drawing::Size(163, 22);
			this->êğóãToolStripMenuItem2->Text = L"Êğóã";
			this->êğóãToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::êğóãToolStripMenuItem2_Click);
			// 
			// ïğÿìîóãîëüíèêToolStripMenuItem2
			// 
			this->ïğÿìîóãîëüíèêToolStripMenuItem2->Name = L"ïğÿìîóãîëüíèêToolStripMenuItem2";
			this->ïğÿìîóãîëüíèêToolStripMenuItem2->Size = System::Drawing::Size(163, 22);
			this->ïğÿìîóãîëüíèêToolStripMenuItem2->Text = L"Ïğÿìîóãîëüíèê";
			this->ïğÿìîóãîëüíèêToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::ïğÿìîóãîëüíèêToolStripMenuItem2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1253, 731);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"UP 7";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void MyForm_Load(Object^  sender, EventArgs^  e) {
				 
	}
	private: System::Void êğóãToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 cflag = true;
				 pictureBox1->Refresh();
	}
	private: System::Void ïğÿìîóãîëüíèêToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 rflag = true;
				 pictureBox1->Refresh();
	}
	private: System::Void î÷èñòèòüToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 cflag = false;
				 rflag = false;
				 pictureBox1->Refresh();
	}
	private: System::Void êğóãToolStripMenuItem1_Click(Object^  sender, EventArgs^  e) {
				 if (!cflag)
				 {
					 MessageBox::Show("Êğóã íå íàéäåí!");
				 }
				 else
				 {
					 MessageBox::Show("Ïëîùàäü êğóãà: " + Convert::ToString(circ.getSquare()));
				 }
	}
	private: System::Void ïğÿìîóãîëüíèêToolStripMenuItem1_Click(Object^  sender, EventArgs^  e) {
				 if (!rflag)
				 {
					 MessageBox::Show("Ïğÿìîóãîëüíèê íå íàéäåí!");
				 }
				 else
				 {
					 MessageBox::Show("Ïëîùàäü ïğÿìîóãîëüíèêà: " + Convert::ToString(rectan.getSquare()));
				 }
	}
	private: System::Void êğóãToolStripMenuItem2_Click(Object^  sender, EventArgs^  e) {
				 if (!cflag)
				 {
					 MessageBox::Show("Êğóã íå íàéäåí!");
				 }
				 else
				 {
					 MessageBox::Show("Ïåğèìåòğ êğóãà: " + Convert::ToString(circ.getPerimeter()));
				 }
	}
	private: System::Void ïğÿìîóãîëüíèêToolStripMenuItem2_Click(Object^  sender, EventArgs^  e) {
				 if (!rflag)
				 {
					 MessageBox::Show("Ïğÿìîóãîëüíèê íå íàéäåí!");
				 }
				 else
				 {
					 MessageBox::Show("Ïåğèìåòğ ïğÿìîóãîëüíèêà: " + Convert::ToString(rectan.getPerimeter()));
				 }
	}
	private: System::Void pictureBox1_Paint(Object^  sender, PaintEventArgs^  e) {
				 if (cflag)
				 {
					 e->Graphics->FillEllipse(Brushes::Red,
						 circ.getLXY(0) - (int)circ.getR(), circ.getLXY(1) - (int)circ.getR(), 2 * (int)circ.getR(), 2 * (int)circ.getR());
				 }
				 if (rflag)
				 {
					 e->Graphics->FillRectangle(Brushes::Green,
						 rectan.getLXY(0), rectan.getLXY(1), rectan.getRXY(0) - rectan.getLXY(0), rectan.getRXY(1) - rectan.getLXY(1));
				 }
	}
	private: System::Void pictureBox1_MouseDown(Object^  sender, MouseEventArgs^  e) {
				 if (e->Button == ::MouseButtons::Left && cflag
					 && abs(e->X - circ.getLXY(0)) <= circ.getR() && abs(e->Y - circ.getLXY(1)) <= circ.getR())
				 {
					 cActive = true;
				 }
				 if (e->Button == ::MouseButtons::Left && rflag 
					 && e->X >= rectan.getLXY(0) && e->Y >= rectan.getLXY(1) && e->X <= rectan.getRXY(0) && e->Y <= rectan.getRXY(1))
				 {
					 rActive = true;
				 }
	}
	private: System::Void pictureBox1_MouseUp(Object^  sender, MouseEventArgs^  e) {
				 cActive = false;
				 rActive = false;
	}
	private: System::Void pictureBox1_MouseMove(Object^  sender, MouseEventArgs^  e) {
				 if (Control::ModifierKeys == Keys::Shift && cflag && (abs(e->X - circ.getRXY(0)) < 20 && abs(e->Y - circ.getRXY(1)) < 20))
				 {
					 ::Cursor::Current = Cursors::SizeNS;
				 }
				 if (Control::ModifierKeys == Keys::Shift && rflag && (abs(e->X - rectan.getRXY(0)) < 20 && abs(e->Y - rectan.getRXY(1)) < 20))
				 {
					 ::Cursor::Current = Cursors::SizeNWSE;
				 }
				 if (e->Button == ::MouseButtons::Left)
				 {
					 if (Control::ModifierKeys == Keys::Shift)
					 {
						 if (cActive && abs(e->X - circ.getRXY(0)) < 20 && abs(e->Y - circ.getRXY(1)) < 20)
						 {
							 circ.fAlteration(e->X - circ.getRXY(0), e->Y - circ.getRXY(1));
							 pictureBox1->Refresh();
						 }
						 if (rActive && abs(e->X - rectan.getRXY(0)) < 20 && abs(e->Y - rectan.getRXY(1)) < 20)
						 {
							 rectan.fAlteration(e->X - rectan.getRXY(0), e->Y - rectan.getRXY(1));
							 pictureBox1->Refresh();
						 }
					 }
					 else
					 {
						 if (cActive)
						 {
							 circ.fMove(e->X - circ.getLXY(0), e->Y - circ.getLXY(1));
							 pictureBox1->Refresh();
						 }
						 if (rActive)
						 {
							 rectan.fMove(e->X - rectan.getLXY(0), e->Y - rectan.getLXY(1));
							 pictureBox1->Refresh();
						 }
					 }
				 }
	}
};
}
