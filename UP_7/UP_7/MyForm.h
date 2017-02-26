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
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem2;
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
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->������ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->��������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1253, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->�������������ToolStripMenuItem, this->��������ToolStripMenuItem
			});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->������ToolStripMenuItem->Text = L"������";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->�������������ToolStripMenuItem->Text = L"�������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem1,
					this->�������������ToolStripMenuItem1
			});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ����ToolStripMenuItem1
			// 
			this->����ToolStripMenuItem1->Name = L"����ToolStripMenuItem1";
			this->����ToolStripMenuItem1->Size = System::Drawing::Size(163, 22);
			this->����ToolStripMenuItem1->Text = L"����";
			this->����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem1_Click);
			// 
			// �������������ToolStripMenuItem1
			// 
			this->�������������ToolStripMenuItem1->Name = L"�������������ToolStripMenuItem1";
			this->�������������ToolStripMenuItem1->Size = System::Drawing::Size(163, 22);
			this->�������������ToolStripMenuItem1->Text = L"�������������";
			this->�������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::�������������ToolStripMenuItem1_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem2,
					this->�������������ToolStripMenuItem2
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ����ToolStripMenuItem2
			// 
			this->����ToolStripMenuItem2->Name = L"����ToolStripMenuItem2";
			this->����ToolStripMenuItem2->Size = System::Drawing::Size(163, 22);
			this->����ToolStripMenuItem2->Text = L"����";
			this->����ToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem2_Click);
			// 
			// �������������ToolStripMenuItem2
			// 
			this->�������������ToolStripMenuItem2->Name = L"�������������ToolStripMenuItem2";
			this->�������������ToolStripMenuItem2->Size = System::Drawing::Size(163, 22);
			this->�������������ToolStripMenuItem2->Text = L"�������������";
			this->�������������ToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::�������������ToolStripMenuItem2_Click);
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
	private: System::Void ����ToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 cflag = true;
				 pictureBox1->Refresh();
	}
	private: System::Void �������������ToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 rflag = true;
				 pictureBox1->Refresh();
	}
	private: System::Void ��������ToolStripMenuItem_Click(Object^  sender, EventArgs^  e) {
				 cflag = false;
				 rflag = false;
				 pictureBox1->Refresh();
	}
	private: System::Void ����ToolStripMenuItem1_Click(Object^  sender, EventArgs^  e) {
				 if (!cflag)
				 {
					 MessageBox::Show("���� �� ������!");
				 }
				 else
				 {
					 MessageBox::Show("������� �����: " + Convert::ToString(circ.getSquare()));
				 }
	}
	private: System::Void �������������ToolStripMenuItem1_Click(Object^  sender, EventArgs^  e) {
				 if (!rflag)
				 {
					 MessageBox::Show("������������� �� ������!");
				 }
				 else
				 {
					 MessageBox::Show("������� ��������������: " + Convert::ToString(rectan.getSquare()));
				 }
	}
	private: System::Void ����ToolStripMenuItem2_Click(Object^  sender, EventArgs^  e) {
				 if (!cflag)
				 {
					 MessageBox::Show("���� �� ������!");
				 }
				 else
				 {
					 MessageBox::Show("�������� �����: " + Convert::ToString(circ.getPerimeter()));
				 }
	}
	private: System::Void �������������ToolStripMenuItem2_Click(Object^  sender, EventArgs^  e) {
				 if (!rflag)
				 {
					 MessageBox::Show("������������� �� ������!");
				 }
				 else
				 {
					 MessageBox::Show("�������� ��������������: " + Convert::ToString(rectan.getPerimeter()));
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
