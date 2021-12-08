#include<iostream>
#include<vector>
#include<string>
#include "Objectively.h"
#include "Best_Option.h"

#pragma once


		/*
		Объявление матрицы -- текущая позиция
		   0 - пусто
		   1 - ладья белых, -1 - ладья чёрных
		   2 - конь белых, -2 - конь чёрных
		   3 - слон белых, -3 - слон чёрных
		   4 - ферзь белых, -4 - ферзь чёрных
		   5 - король белых, -5 - король чёрных
		   6 - пешка белых, -6 - пешка чёрных
		*/
vector<vector<int>> theMatrix;

//{ {i1, j1}, {i2, j2} }
vector<vector<int>> positions;

int pawn_turnInto = 4;
bool whites_turn = 1, picked = 0, playing_white = 1, PvP = 0;

void drawbtn(System::Windows::Forms::Button^ button, int num, System::ComponentModel::ComponentResourceManager^ resources)
{
	switch (num)
	{
	case 0: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NULL")));
		break;
	}
	case 1: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whlad")));
		break;
	}
	case -1: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bllad")));
		break;
	}
	case 2: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whkon")));
		break;
	}
	case -2: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blkon")));
		break;
	}
	case 3: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whslo")));
		break;
	}
	case -3: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blslo")));
		break;
	}
	case 4: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whfer")));
		break;
	}
	case -4: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blfer")));
		break;
	}
	case 5: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whkor")));
		break;
	}
	case -5: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blkor")));
		break;
	}
	case 6: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
		break;
	}
	case -6: {
		button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
		break;
	}
	}
}

namespace Chess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button44;
	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::Button^ button49;
	private: System::Windows::Forms::Button^ button50;
	private: System::Windows::Forms::Button^ button51;
	private: System::Windows::Forms::Button^ button52;
	private: System::Windows::Forms::Button^ button53;
	private: System::Windows::Forms::Button^ button54;
	private: System::Windows::Forms::Button^ button55;
	private: System::Windows::Forms::Button^ button56;
	private: System::Windows::Forms::Button^ button57;
	private: System::Windows::Forms::Button^ button58;
	private: System::Windows::Forms::Button^ button59;
	private: System::Windows::Forms::Button^ button60;
	private: System::Windows::Forms::Button^ button61;
	private: System::Windows::Forms::Button^ button62;
	private: System::Windows::Forms::Button^ button63;
	private: System::Windows::Forms::Button^ button64;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ button66;
	private: System::Windows::Forms::Button^ button67;
	private: System::Windows::Forms::Button^ button68;
	private: System::Windows::Forms::Button^ button69;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button70;
	private: System::Windows::Forms::Button^ button71;
	private: System::Windows::Forms::Button^ button72;
	private: System::Windows::Forms::Button^ button65;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->button60 = (gcnew System::Windows::Forms::Button());
			this->button61 = (gcnew System::Windows::Forms::Button());
			this->button62 = (gcnew System::Windows::Forms::Button());
			this->button63 = (gcnew System::Windows::Forms::Button());
			this->button64 = (gcnew System::Windows::Forms::Button());
			this->button65 = (gcnew System::Windows::Forms::Button());
			this->button66 = (gcnew System::Windows::Forms::Button());
			this->button67 = (gcnew System::Windows::Forms::Button());
			this->button68 = (gcnew System::Windows::Forms::Button());
			this->button69 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button70 = (gcnew System::Windows::Forms::Button());
			this->button71 = (gcnew System::Windows::Forms::Button());
			this->button72 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(636, 602);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 70);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(712, 602);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 70);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(788, 602);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 70);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(864, 602);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 70);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(940, 602);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 70);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1016, 602);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 70);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1092, 602);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 70);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1168, 602);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 70);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(636, 526);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(70, 70);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(712, 526);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(70, 70);
			this->button10->TabIndex = 9;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(788, 526);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(70, 70);
			this->button11->TabIndex = 10;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(864, 526);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(70, 70);
			this->button12->TabIndex = 11;
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(940, 526);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(70, 70);
			this->button13->TabIndex = 12;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(1016, 526);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(70, 70);
			this->button14->TabIndex = 13;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(1092, 526);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(70, 70);
			this->button15->TabIndex = 14;
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(1168, 526);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(70, 70);
			this->button16->TabIndex = 15;
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(636, 450);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(70, 70);
			this->button17->TabIndex = 16;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(712, 450);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(70, 70);
			this->button18->TabIndex = 17;
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(788, 450);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(70, 70);
			this->button19->TabIndex = 18;
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(864, 450);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(70, 70);
			this->button20->TabIndex = 19;
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(940, 450);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(70, 70);
			this->button21->TabIndex = 20;
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(1016, 450);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(70, 70);
			this->button22->TabIndex = 21;
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(1092, 450);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(70, 70);
			this->button23->TabIndex = 22;
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(1168, 450);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(70, 70);
			this->button24->TabIndex = 23;
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(636, 374);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(70, 70);
			this->button25->TabIndex = 24;
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(712, 374);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(70, 70);
			this->button26->TabIndex = 25;
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(788, 374);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(70, 70);
			this->button27->TabIndex = 26;
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(864, 374);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(70, 70);
			this->button28->TabIndex = 27;
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(940, 374);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(70, 70);
			this->button29->TabIndex = 28;
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(1016, 374);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(70, 70);
			this->button30->TabIndex = 29;
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(1092, 374);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(70, 70);
			this->button31->TabIndex = 30;
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(1168, 374);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(70, 70);
			this->button32->TabIndex = 31;
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(636, 298);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(70, 70);
			this->button33->TabIndex = 32;
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(712, 298);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(70, 70);
			this->button34->TabIndex = 33;
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(788, 298);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(70, 70);
			this->button35->TabIndex = 34;
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(864, 298);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(70, 70);
			this->button36->TabIndex = 35;
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// button37
			// 
			this->button37->Location = System::Drawing::Point(940, 298);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(70, 70);
			this->button37->TabIndex = 36;
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
			// 
			// button38
			// 
			this->button38->Location = System::Drawing::Point(1016, 298);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(70, 70);
			this->button38->TabIndex = 37;
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
			// 
			// button39
			// 
			this->button39->Location = System::Drawing::Point(1092, 298);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(70, 70);
			this->button39->TabIndex = 38;
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
			// 
			// button40
			// 
			this->button40->Location = System::Drawing::Point(1168, 298);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(70, 70);
			this->button40->TabIndex = 39;
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
			// 
			// button41
			// 
			this->button41->Location = System::Drawing::Point(636, 222);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(70, 70);
			this->button41->TabIndex = 40;
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &MyForm::button41_Click);
			// 
			// button42
			// 
			this->button42->Location = System::Drawing::Point(712, 222);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(70, 70);
			this->button42->TabIndex = 41;
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::button42_Click);
			// 
			// button43
			// 
			this->button43->Location = System::Drawing::Point(788, 222);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(70, 70);
			this->button43->TabIndex = 42;
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
			// 
			// button44
			// 
			this->button44->Location = System::Drawing::Point(864, 222);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(70, 70);
			this->button44->TabIndex = 43;
			this->button44->UseVisualStyleBackColor = true;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::button44_Click);
			// 
			// button45
			// 
			this->button45->Location = System::Drawing::Point(940, 222);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(70, 70);
			this->button45->TabIndex = 44;
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
			// 
			// button46
			// 
			this->button46->Location = System::Drawing::Point(1016, 222);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(70, 70);
			this->button46->TabIndex = 45;
			this->button46->UseVisualStyleBackColor = true;
			this->button46->Click += gcnew System::EventHandler(this, &MyForm::button46_Click);
			// 
			// button47
			// 
			this->button47->Location = System::Drawing::Point(1092, 222);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(70, 70);
			this->button47->TabIndex = 46;
			this->button47->UseVisualStyleBackColor = true;
			this->button47->Click += gcnew System::EventHandler(this, &MyForm::button47_Click);
			// 
			// button48
			// 
			this->button48->Location = System::Drawing::Point(1168, 222);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(70, 70);
			this->button48->TabIndex = 47;
			this->button48->UseVisualStyleBackColor = true;
			this->button48->Click += gcnew System::EventHandler(this, &MyForm::button48_Click);
			// 
			// button49
			// 
			this->button49->Location = System::Drawing::Point(636, 146);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(70, 70);
			this->button49->TabIndex = 48;
			this->button49->UseVisualStyleBackColor = true;
			this->button49->Click += gcnew System::EventHandler(this, &MyForm::button49_Click);
			// 
			// button50
			// 
			this->button50->Location = System::Drawing::Point(712, 146);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(70, 70);
			this->button50->TabIndex = 49;
			this->button50->UseVisualStyleBackColor = true;
			this->button50->Click += gcnew System::EventHandler(this, &MyForm::button50_Click);
			// 
			// button51
			// 
			this->button51->Location = System::Drawing::Point(788, 146);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(70, 70);
			this->button51->TabIndex = 50;
			this->button51->UseVisualStyleBackColor = true;
			this->button51->Click += gcnew System::EventHandler(this, &MyForm::button51_Click);
			// 
			// button52
			// 
			this->button52->Location = System::Drawing::Point(864, 146);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(70, 70);
			this->button52->TabIndex = 51;
			this->button52->UseVisualStyleBackColor = true;
			this->button52->Click += gcnew System::EventHandler(this, &MyForm::button52_Click);
			// 
			// button53
			// 
			this->button53->Location = System::Drawing::Point(940, 146);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(70, 70);
			this->button53->TabIndex = 52;
			this->button53->UseVisualStyleBackColor = true;
			this->button53->Click += gcnew System::EventHandler(this, &MyForm::button53_Click);
			// 
			// button54
			// 
			this->button54->Location = System::Drawing::Point(1016, 146);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(70, 70);
			this->button54->TabIndex = 53;
			this->button54->UseVisualStyleBackColor = true;
			this->button54->Click += gcnew System::EventHandler(this, &MyForm::button54_Click);
			// 
			// button55
			// 
			this->button55->Location = System::Drawing::Point(1092, 146);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(70, 70);
			this->button55->TabIndex = 54;
			this->button55->UseVisualStyleBackColor = true;
			this->button55->Click += gcnew System::EventHandler(this, &MyForm::button55_Click);
			// 
			// button56
			// 
			this->button56->Location = System::Drawing::Point(1168, 146);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(70, 70);
			this->button56->TabIndex = 55;
			this->button56->UseVisualStyleBackColor = true;
			this->button56->Click += gcnew System::EventHandler(this, &MyForm::button56_Click);
			// 
			// button57
			// 
			this->button57->Location = System::Drawing::Point(636, 70);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(70, 70);
			this->button57->TabIndex = 56;
			this->button57->UseVisualStyleBackColor = true;
			this->button57->Click += gcnew System::EventHandler(this, &MyForm::button57_Click);
			// 
			// button58
			// 
			this->button58->Location = System::Drawing::Point(712, 70);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(70, 70);
			this->button58->TabIndex = 57;
			this->button58->UseVisualStyleBackColor = true;
			this->button58->Click += gcnew System::EventHandler(this, &MyForm::button58_Click);
			// 
			// button59
			// 
			this->button59->Location = System::Drawing::Point(788, 70);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(70, 70);
			this->button59->TabIndex = 58;
			this->button59->UseVisualStyleBackColor = true;
			this->button59->Click += gcnew System::EventHandler(this, &MyForm::button59_Click);
			// 
			// button60
			// 
			this->button60->Location = System::Drawing::Point(864, 70);
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(70, 70);
			this->button60->TabIndex = 59;
			this->button60->UseVisualStyleBackColor = true;
			this->button60->Click += gcnew System::EventHandler(this, &MyForm::button60_Click);
			// 
			// button61
			// 
			this->button61->Location = System::Drawing::Point(940, 70);
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(70, 70);
			this->button61->TabIndex = 60;
			this->button61->UseVisualStyleBackColor = true;
			this->button61->Click += gcnew System::EventHandler(this, &MyForm::button61_Click);
			// 
			// button62
			// 
			this->button62->Location = System::Drawing::Point(1016, 70);
			this->button62->Name = L"button62";
			this->button62->Size = System::Drawing::Size(70, 70);
			this->button62->TabIndex = 61;
			this->button62->UseVisualStyleBackColor = true;
			this->button62->Click += gcnew System::EventHandler(this, &MyForm::button62_Click);
			// 
			// button63
			// 
			this->button63->Location = System::Drawing::Point(1092, 70);
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(70, 70);
			this->button63->TabIndex = 62;
			this->button63->UseVisualStyleBackColor = true;
			this->button63->Click += gcnew System::EventHandler(this, &MyForm::button63_Click);
			// 
			// button64
			// 
			this->button64->Location = System::Drawing::Point(1168, 70);
			this->button64->Name = L"button64";
			this->button64->Size = System::Drawing::Size(70, 70);
			this->button64->TabIndex = 63;
			this->button64->UseVisualStyleBackColor = true;
			this->button64->Click += gcnew System::EventHandler(this, &MyForm::button64_Click);
			// 
			// button65
			// 
			this->button65->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button65.Image")));
			this->button65->Location = System::Drawing::Point(1244, 13);
			this->button65->Name = L"button65";
			this->button65->Size = System::Drawing::Size(75, 671);
			this->button65->TabIndex = 64;
			this->button65->UseVisualStyleBackColor = true;
			this->button65->Click += gcnew System::EventHandler(this, &MyForm::button65_Click);
			// 
			// button66
			// 
			this->button66->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button66.Image")));
			this->button66->Location = System::Drawing::Point(1168, 13);
			this->button66->Name = L"button66";
			this->button66->Size = System::Drawing::Size(70, 71);
			this->button66->TabIndex = 65;
			this->button66->UseVisualStyleBackColor = true;
			this->button66->Click += gcnew System::EventHandler(this, &MyForm::button66_Click);
			// 
			// button67
			// 
			this->button67->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button67.Image")));
			this->button67->Location = System::Drawing::Point(1092, 13);
			this->button67->Name = L"button67";
			this->button67->Size = System::Drawing::Size(70, 71);
			this->button67->TabIndex = 66;
			this->button67->UseVisualStyleBackColor = true;
			this->button67->Click += gcnew System::EventHandler(this, &MyForm::button67_Click);
			// 
			// button68
			// 
			this->button68->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button68.Image")));
			this->button68->Location = System::Drawing::Point(1168, 90);
			this->button68->Name = L"button68";
			this->button68->Size = System::Drawing::Size(70, 72);
			this->button68->TabIndex = 67;
			this->button68->UseVisualStyleBackColor = true;
			this->button68->Click += gcnew System::EventHandler(this, &MyForm::button68_Click);
			// 
			// button69
			// 
			this->button69->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button69.Image")));
			this->button69->Location = System::Drawing::Point(1092, 90);
			this->button69->Name = L"button69";
			this->button69->Size = System::Drawing::Size(70, 72);
			this->button69->TabIndex = 68;
			this->button69->UseVisualStyleBackColor = true;
			this->button69->Click += gcnew System::EventHandler(this, &MyForm::button69_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1089, 173);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 17);
			this->label1->TabIndex = 69;
			this->label1->Text = L"No can do";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1092, 194);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 70;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1092, 249);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 17);
			this->label3->TabIndex = 71;
			this->label3->Text = L"Picked:";
			// 
			// button70
			// 
			this->button70->Location = System::Drawing::Point(1026, 12);
			this->button70->Name = L"button70";
			this->button70->Size = System::Drawing::Size(60, 70);
			this->button70->TabIndex = 72;
			this->button70->Text = L"Play as White";
			this->button70->UseVisualStyleBackColor = true;
			this->button70->Click += gcnew System::EventHandler(this, &MyForm::button70_Click);
			// 
			// button71
			// 
			this->button71->Location = System::Drawing::Point(1026, 88);
			this->button71->Name = L"button71";
			this->button71->Size = System::Drawing::Size(60, 71);
			this->button71->TabIndex = 73;
			this->button71->Text = L"Play as Black";
			this->button71->UseVisualStyleBackColor = true;
			this->button71->Click += gcnew System::EventHandler(this, &MyForm::button71_Click);
			// 
			// button72
			// 
			this->button72->Location = System::Drawing::Point(1026, 165);
			this->button72->Name = L"button72";
			this->button72->Size = System::Drawing::Size(60, 71);
			this->button72->TabIndex = 74;
			this->button72->Text = L"Play PvP";
			this->button72->UseVisualStyleBackColor = true;
			this->button72->Click += gcnew System::EventHandler(this, &MyForm::button72_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1331, 696);
			this->Controls->Add(this->button72);
			this->Controls->Add(this->button71);
			this->Controls->Add(this->button70);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button69);
			this->Controls->Add(this->button68);
			this->Controls->Add(this->button67);
			this->Controls->Add(this->button66);
			this->Controls->Add(this->button65);
			this->Controls->Add(this->button64);
			this->Controls->Add(this->button63);
			this->Controls->Add(this->button62);
			this->Controls->Add(this->button61);
			this->Controls->Add(this->button60);
			this->Controls->Add(this->button59);
			this->Controls->Add(this->button58);
			this->Controls->Add(this->button57);
			this->Controls->Add(this->button56);
			this->Controls->Add(this->button55);
			this->Controls->Add(this->button54);
			this->Controls->Add(this->button53);
			this->Controls->Add(this->button52);
			this->Controls->Add(this->button51);
			this->Controls->Add(this->button50);
			this->Controls->Add(this->button49);
			this->Controls->Add(this->button48);
			this->Controls->Add(this->button47);
			this->Controls->Add(this->button46);
			this->Controls->Add(this->button45);
			this->Controls->Add(this->button44);
			this->Controls->Add(this->button43);
			this->Controls->Add(this->button42);
			this->Controls->Add(this->button41);
			this->Controls->Add(this->button40);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button38);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Chess";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		
	private: System::Void button65_Click(System::Object^ sender, System::EventArgs^ e) {
					theMatrix =	{/*0*/ { 1,  2,  3,  5,  4,  3,  2,  1},
								 /*1*/ { 6,  6,  6,  6,  6,  6,  6,  6},
								 /*2*/ { 0,  0,  0,  0,  0,  0,  0,  0}, 
								 /*3*/ { 0,  0,  0,  0,  0,  0,  0,  0}, 
								 /*4*/ { 0,  0,  0,  0,  0,  0,  0,  0},
								 /*5*/ { 0,  0,  0,  0,  0,  0,  0,  0},
								 /*6*/ {-6, -6, -6, -6, -6, -6, -6, -6},
								 /*7*/ {-1, -2, -3, -5, -4, -3, -2, -1},
								//       0   1   2   3   4   5   6   7
								 /*8*/ {1, 1, 1, 1}};
					//Последний ряд отвечает за спец.условия. [8][0], [8][1] -- за право на соответственно короткую и длинную рокировку для белых
					//[8][2], [8][3] -- за право на соответственно короткую и длинную рокировку для чёрных
					//Также опционально могут быть [8][4] и [8][5] -- координаты поля для взятия на проходе
		this->button65->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NULL")));
		whites_turn = 1;
		if (PvP || playing_white)
			picked = 0;
		else // if (!PvP && !playing_white)
			picked = 1; // ЕЕЕЕ костыли
		{
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bllad")));
			this->button1->Location = System::Drawing::Point(70 * (0 / 8), 70 * (0 % 8));
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 70);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button2->Location = System::Drawing::Point(70 * (1 / 8), 70 * (1 % 8));
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 70);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(70 * (2 / 8), 70 * (2 % 8));
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 70);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(70 * (3 / 8), 70 * (3 % 8));
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 70);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(70 * (4 / 8), 70 * (4 % 8));
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 70);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(70 * (5 / 8), 70 * (5 % 8));
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 70);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button7->Location = System::Drawing::Point(70 * (6 / 8), 70 * (6 % 8));
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(70, 70);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whlad")));
			this->button8->Location = System::Drawing::Point(70 * (7 / 8), 70 * (7 % 8));
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(70, 70);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blkon")));
			this->button9->Location = System::Drawing::Point(70 * (8 / 8), 70 * (8 % 8));
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(70, 70);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button10->Location = System::Drawing::Point(70 * (9 / 8), 70 * (9 % 8));
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(70, 70);
			this->button10->TabIndex = 9;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(70 * (10 / 8), 70 * (10 % 8));
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(70, 70);
			this->button11->TabIndex = 10;
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(70 * (11 / 8), 70 * (11 % 8));
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(70, 70);
			this->button12->TabIndex = 11;
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(70 * (12 / 8), 70 * (12 % 8));
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(70, 70);
			this->button13->TabIndex = 12;
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(70 * (13 / 8), 70 * (13 % 8));
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(70, 70);
			this->button14->TabIndex = 13;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button15->Location = System::Drawing::Point(70 * (14 / 8), 70 * (14 % 8));
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(70, 70);
			this->button15->TabIndex = 14;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whkon")));
			this->button16->Location = System::Drawing::Point(70 * (15 / 8), 70 * (15 % 8));
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(70, 70);
			this->button16->TabIndex = 15;
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blslo")));
			this->button17->Location = System::Drawing::Point(70 * (16 / 8), 70 * (16 % 8));
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(70, 70);
			this->button17->TabIndex = 16;
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button18->Location = System::Drawing::Point(70 * (17 / 8), 70 * (17 % 8));
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(70, 70);
			this->button18->TabIndex = 17;
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(70 * (18 / 8), 70 * (18 % 8));
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(70, 70);
			this->button19->TabIndex = 18;
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(70 * (19 / 8), 70 * (19 % 8));
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(70, 70);
			this->button20->TabIndex = 19;
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(70 * (20 / 8), 70 * (20 % 8));
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(70, 70);
			this->button21->TabIndex = 20;
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(70 * (21 / 8), 70 * (21 % 8));
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(70, 70);
			this->button22->TabIndex = 21;
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button23->Location = System::Drawing::Point(70 * (22 / 8), 70 * (22 % 8));
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(70, 70);
			this->button23->TabIndex = 22;
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whslo")));
			this->button24->Location = System::Drawing::Point(70 * (23 / 8), 70 * (23 % 8));
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(70, 70);
			this->button24->TabIndex = 23;
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blfer")));
			this->button25->Location = System::Drawing::Point(70 * (24 / 8), 70 * (24 % 8));
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(70, 70);
			this->button25->TabIndex = 24;
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button26->Location = System::Drawing::Point(70 * (25 / 8), 70 * (25 % 8));
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(70, 70);
			this->button26->TabIndex = 25;
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(70 * (26 / 8), 70 * (26 % 8));
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(70, 70);
			this->button27->TabIndex = 26;
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(70 * (27 / 8), 70 * (27 % 8));
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(70, 70);
			this->button28->TabIndex = 27;
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(70 * (28 / 8), 70 * (28 % 8));
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(70, 70);
			this->button29->TabIndex = 28;
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(70 * (29 / 8), 70 * (29 % 8));
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(70, 70);
			this->button30->TabIndex = 29;
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button31->Location = System::Drawing::Point(70 * (30 / 8), 70 * (30 % 8));
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(70, 70);
			this->button31->TabIndex = 30;
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whfer")));
			this->button32->Location = System::Drawing::Point(70 * (31 / 8), 70 * (31 % 8));
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(70, 70);
			this->button32->TabIndex = 31;
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blkor")));
			this->button33->Location = System::Drawing::Point(70 * (32 / 8), 70 * (32 % 8));
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(70, 70);
			this->button33->TabIndex = 32;
			this->button33->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button34->Location = System::Drawing::Point(70 * (33 / 8), 70 * (33 % 8));
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(70, 70);
			this->button34->TabIndex = 33;
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(70 * (34 / 8), 70 * (34 % 8));
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(70, 70);
			this->button35->TabIndex = 34;
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(70 * (35 / 8), 70 * (35 % 8));
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(70, 70);
			this->button36->TabIndex = 35;
			this->button36->UseVisualStyleBackColor = true;
			// 
			// button37
			// 
			this->button37->Location = System::Drawing::Point(70 * (36 / 8), 70 * (36 % 8));
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(70, 70);
			this->button37->TabIndex = 36;
			this->button37->UseVisualStyleBackColor = true;
			// 
			// button38
			// 
			this->button38->Location = System::Drawing::Point(70 * (37 / 8), 70 * (37 % 8));
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(70, 70);
			this->button38->TabIndex = 37;
			this->button38->UseVisualStyleBackColor = true;
			// 
			// button39
			// 
			this->button39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button39->Location = System::Drawing::Point(70 * (38 / 8), 70 * (38 % 8));
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(70, 70);
			this->button39->TabIndex = 38;
			this->button39->UseVisualStyleBackColor = true;
			// 
			// button40
			// 
			this->button40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whkor")));
			this->button40->Location = System::Drawing::Point(70 * (39 / 8), 70 * (39 % 8));
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(70, 70);
			this->button40->TabIndex = 39;
			this->button40->UseVisualStyleBackColor = true;
			// 
			// button41
			// 
			this->button41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blslo")));
			this->button41->Location = System::Drawing::Point(70 * (40 / 8), 70 * (40 % 8));
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(70, 70);
			this->button41->TabIndex = 40;
			this->button41->UseVisualStyleBackColor = true;
			// 
			// button42
			// 
			this->button42->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button42->Location = System::Drawing::Point(70 * (41 / 8), 70 * (41 % 8));
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(70, 70);
			this->button42->TabIndex = 41;
			this->button42->UseVisualStyleBackColor = true;
			// 
			// button43
			// 
			this->button43->Location = System::Drawing::Point(70 * (42 / 8), 70 * (42 % 8));
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(70, 70);
			this->button43->TabIndex = 42;
			this->button43->UseVisualStyleBackColor = true;
			// 
			// button44
			// 
			this->button44->Location = System::Drawing::Point(70 * (43 / 8), 70 * (43 % 8));
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(70, 70);
			this->button44->TabIndex = 43;
			this->button44->UseVisualStyleBackColor = true;
			// 
			// button45
			// 
			this->button45->Location = System::Drawing::Point(70 * (44 / 8), 70 * (44 % 8));
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(70, 70);
			this->button45->TabIndex = 44;
			this->button45->UseVisualStyleBackColor = true;
			// 
			// button46
			// 
			this->button46->Location = System::Drawing::Point(70 * (45 / 8), 70 * (45 % 8));
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(70, 70);
			this->button46->TabIndex = 45;
			this->button46->UseVisualStyleBackColor = true;
			// 
			// button47
			// 
			this->button47->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button47->Location = System::Drawing::Point(70 * (46 / 8), 70 * (46 % 8));
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(70, 70);
			this->button47->TabIndex = 46;
			this->button47->UseVisualStyleBackColor = true;
			// 
			// button48
			// 
			this->button48->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whslo")));
			this->button48->Location = System::Drawing::Point(70 * (47 / 8), 70 * (47 % 8));
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(70, 70);
			this->button48->TabIndex = 47;
			this->button48->UseVisualStyleBackColor = true;
			// 
			// button49
			// 
			this->button49->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blkon")));
			this->button49->Location = System::Drawing::Point(70 * (48 / 8), 70 * (48 % 8));
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(70, 70);
			this->button49->TabIndex = 48;
			this->button49->UseVisualStyleBackColor = true;
			// 
			// button50
			// 
			this->button50->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button50->Location = System::Drawing::Point(70 * (49 / 8), 70 * (49 % 8));
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(70, 70);
			this->button50->TabIndex = 49;
			this->button50->UseVisualStyleBackColor = true;
			// 
			// button51
			// 
			this->button51->Location = System::Drawing::Point(70 * (50 / 8), 70 * (50 % 8));
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(70, 70);
			this->button51->TabIndex = 50;
			this->button51->UseVisualStyleBackColor = true;
			// 
			// button52
			// 
			this->button52->Location = System::Drawing::Point(70 * (51 / 8), 70 * (51 % 8));
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(70, 70);
			this->button52->TabIndex = 51;
			this->button52->UseVisualStyleBackColor = true;
			// 
			// button53
			// 
			this->button53->Location = System::Drawing::Point(70 * (52 / 8), 70 * (52 % 8));
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(70, 70);
			this->button53->TabIndex = 52;
			this->button53->UseVisualStyleBackColor = true;
			// 
			// button54
			// 
			this->button54->Location = System::Drawing::Point(70 * (53 / 8), 70 * (53 % 8));
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(70, 70);
			this->button54->TabIndex = 53;
			this->button54->UseVisualStyleBackColor = true;
			// 
			// button55
			// 
			this->button55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button55->Location = System::Drawing::Point(70 * (54 / 8), 70 * (54 % 8));
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(70, 70);
			this->button55->TabIndex = 54;
			this->button55->UseVisualStyleBackColor = true;
			// 
			// button56
			// 
			this->button56->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whkon")));
			this->button56->Location = System::Drawing::Point(70 * (55 / 8), 70 * (55 % 8));
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(70, 70);
			this->button56->TabIndex = 55;
			this->button56->UseVisualStyleBackColor = true;
			// 
			// button57
			// 
			this->button57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bllad")));
			this->button57->Location = System::Drawing::Point(70 * (56 / 8), 70 * (56 % 8));
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(70, 70);
			this->button57->TabIndex = 56;
			this->button57->UseVisualStyleBackColor = true;
			// 
			// button58
			// 
			this->button58->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blpes")));
			this->button58->Location = System::Drawing::Point(70 * (57 / 8), 70 * (57 % 8));
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(70, 70);
			this->button58->TabIndex = 57;
			this->button58->UseVisualStyleBackColor = true;
			// 
			// button59
			// 
			this->button59->Location = System::Drawing::Point(70 * (58 / 8), 70 * (58 % 8));
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(70, 70);
			this->button59->TabIndex = 58;
			this->button59->UseVisualStyleBackColor = true;
			// 
			// button60
			// 
			this->button60->Location = System::Drawing::Point(70 * (59 / 8), 70 * (59 % 8));
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(70, 70);
			this->button60->TabIndex = 59;
			this->button60->UseVisualStyleBackColor = true;
			// 
			// button61
			// 
			this->button61->Location = System::Drawing::Point(70 * (60 / 8), 70 * (60 % 8));
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(70, 70);
			this->button61->TabIndex = 60;
			this->button61->UseVisualStyleBackColor = true;
			// 
			// button62
			// 
			this->button62->Location = System::Drawing::Point(70 * (61 / 8), 70 * (61 % 8));
			this->button62->Name = L"button62";
			this->button62->Size = System::Drawing::Size(70, 70);
			this->button62->TabIndex = 61;
			this->button62->UseVisualStyleBackColor = true;
			// 
			// button63
			// 
			this->button63->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whpes")));
			this->button63->Location = System::Drawing::Point(70 * (62 / 8), 70 * (62 % 8));
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(70, 70);
			this->button63->TabIndex = 62;
			this->button63->UseVisualStyleBackColor = true;
			// 
			// button64
			// 
			this->button64->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"whlad")));
			this->button64->Location = System::Drawing::Point(70 * (63 / 8), 70 * (63 % 8));
			this->button64->Name = L"button64";
			this->button64->Size = System::Drawing::Size(70, 70);
			this->button64->TabIndex = 63;
			this->button64->UseVisualStyleBackColor = true;
		}
		drawfield();
		if (!playing_white && !PvP)
		{
			vector<int> theMove = bestMove(theMatrix, whites_turn);
			positions = { {theMove[0], theMove[1]}, {theMove[2], theMove[3]} };
			turn_made();
		}
	}
private: System::Void button64_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 7 });
	turn_made();
}
private: System::Void button63_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 7 });
	turn_made();
}
private: System::Void button62_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 7 });
	turn_made();
}
private: System::Void button61_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 7 });
	turn_made();
}
private: System::Void button60_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 7 });
	turn_made();
}
private: System::Void button59_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 7 });
	turn_made();
}
private: System::Void button58_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 7 });
	turn_made();
}
private: System::Void button57_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 7 });
	turn_made();
}
private: System::Void button56_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 6 });
	turn_made();
}
private: System::Void button55_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 6 });
	turn_made();
}
private: System::Void button54_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 6 });
	turn_made();
}
private: System::Void button53_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 6 });
	turn_made();
}
private: System::Void button52_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 6 });
	turn_made();
}
private: System::Void button51_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 6 });
	turn_made();
}
private: System::Void button50_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 6 });
	turn_made();
}
private: System::Void button49_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 6 });
	turn_made();
}
private: System::Void button48_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 5 });
	turn_made();
}
private: System::Void button47_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 5 });
	turn_made();
}
private: System::Void button46_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 5 });
	turn_made();
}
private: System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 5 });
	turn_made();
}
private: System::Void button44_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 5 });
	turn_made();
}
private: System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 5 });
	turn_made();
}
private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 5 });
	turn_made();
}
private: System::Void button41_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 5 });
	turn_made();
}
private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 4 });
	turn_made();
}
private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 4 });
	turn_made();
}
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 4 });
	turn_made();
}
private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 4 });
	turn_made();
}
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 4 });
	turn_made();
}
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 4 });
	turn_made();
}
private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 4 });
	turn_made();
}
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 4 });
	turn_made();
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 3 });
	turn_made();
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 3 });
	turn_made();
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 3 });
	turn_made();
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 3 });
	turn_made();
}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 3 });
	turn_made();
}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 3 });
	turn_made();
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 3 });
	turn_made();
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 3 });
	turn_made();
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 2 });
	turn_made();
}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 2 });
	turn_made();
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 2 });
	turn_made();
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 2 });
	turn_made();
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 2 });
	turn_made();
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 2 });
	turn_made();
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 2 });
	turn_made();
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 2 });
	turn_made();
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 1 });
	turn_made();
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 1 });
	turn_made();
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 1 });
	turn_made();
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 1 });
	turn_made();
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 1 });
	turn_made();
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 1 });
	turn_made();
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 1 });
	turn_made();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 1 });
	turn_made();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 7, 0 });
	turn_made();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 6, 0 });
	turn_made();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 5, 0 });
	turn_made();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 4, 0 });
	turn_made();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 3, 0 });
	turn_made();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 2, 0 });
	turn_made();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 1, 0 });
	turn_made();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	positions.push_back({ 0, 0 });
	turn_made();
}
	   void drawfield()
	   {
		   int cm = check_mate(theMatrix, whites_turn);
		   label2->Text = "whites_turn: " + char(whites_turn) + "\nCheck (2 if mate, 3 if draw): " + char(cm) + "\nPlaying white: " + char(playing_white);
		   {
			   drawbtn(button1, theMatrix[0][0], resources);
			   drawbtn(button2, theMatrix[1][0], resources);
			   drawbtn(button3, theMatrix[2][0], resources);
			   drawbtn(button4, theMatrix[3][0], resources);
			   drawbtn(button5, theMatrix[4][0], resources);
			   drawbtn(button6, theMatrix[5][0], resources);
			   drawbtn(button7, theMatrix[6][0], resources);
			   drawbtn(button8, theMatrix[7][0], resources);
			   drawbtn(button9, theMatrix[0][1], resources);
			   drawbtn(button10, theMatrix[1][1], resources);
			   drawbtn(button11, theMatrix[2][1], resources);
			   drawbtn(button12, theMatrix[3][1], resources);
			   drawbtn(button13, theMatrix[4][1], resources);
			   drawbtn(button14, theMatrix[5][1], resources);
			   drawbtn(button15, theMatrix[6][1], resources);
			   drawbtn(button16, theMatrix[7][1], resources);
			   drawbtn(button17, theMatrix[0][2], resources);
			   drawbtn(button18, theMatrix[1][2], resources);
			   drawbtn(button19, theMatrix[2][2], resources);
			   drawbtn(button20, theMatrix[3][2], resources);
			   drawbtn(button21, theMatrix[4][2], resources);
			   drawbtn(button22, theMatrix[5][2], resources);
			   drawbtn(button23, theMatrix[6][2], resources);
			   drawbtn(button24, theMatrix[7][2], resources);
			   drawbtn(button25, theMatrix[0][3], resources);
			   drawbtn(button26, theMatrix[1][3], resources);
			   drawbtn(button27, theMatrix[2][3], resources);
			   drawbtn(button28, theMatrix[3][3], resources);
			   drawbtn(button29, theMatrix[4][3], resources);
			   drawbtn(button30, theMatrix[5][3], resources);
			   drawbtn(button31, theMatrix[6][3], resources);
			   drawbtn(button32, theMatrix[7][3], resources);
			   drawbtn(button33, theMatrix[0][4], resources);
			   drawbtn(button34, theMatrix[1][4], resources);
			   drawbtn(button35, theMatrix[2][4], resources);
			   drawbtn(button36, theMatrix[3][4], resources);
			   drawbtn(button37, theMatrix[4][4], resources);
			   drawbtn(button38, theMatrix[5][4], resources);
			   drawbtn(button39, theMatrix[6][4], resources);
			   drawbtn(button40, theMatrix[7][4], resources);
			   drawbtn(button41, theMatrix[0][5], resources);
			   drawbtn(button42, theMatrix[1][5], resources);
			   drawbtn(button43, theMatrix[2][5], resources);
			   drawbtn(button44, theMatrix[3][5], resources);
			   drawbtn(button45, theMatrix[4][5], resources);
			   drawbtn(button46, theMatrix[5][5], resources);
			   drawbtn(button47, theMatrix[6][5], resources);
			   drawbtn(button48, theMatrix[7][5], resources);
			   drawbtn(button49, theMatrix[0][6], resources);
			   drawbtn(button50, theMatrix[1][6], resources);
			   drawbtn(button51, theMatrix[2][6], resources);
			   drawbtn(button52, theMatrix[3][6], resources);
			   drawbtn(button53, theMatrix[4][6], resources);
			   drawbtn(button54, theMatrix[5][6], resources);
			   drawbtn(button55, theMatrix[6][6], resources);
			   drawbtn(button56, theMatrix[7][6], resources);
			   drawbtn(button57, theMatrix[0][7], resources);
			   drawbtn(button58, theMatrix[1][7], resources);
			   drawbtn(button59, theMatrix[2][7], resources);
			   drawbtn(button60, theMatrix[3][7], resources);
			   drawbtn(button61, theMatrix[4][7], resources);
			   drawbtn(button62, theMatrix[5][7], resources);
			   drawbtn(button63, theMatrix[6][7], resources);
			   drawbtn(button64, theMatrix[7][7], resources);
		   }
	   }
	   void turn_made()
	   {
		   picked = !picked;
		   label3->Text = "Picked: " + char(picked);
		   if (positions.size() == 2)
		   {
			   if (possible_move(theMatrix, whites_turn, positions[0][0], positions[0][1], positions[1][0], positions[1][1]))
			   {
				   whites_turn = !whites_turn;
				   //Для взятия на проходе
				   if (theMatrix[8].size() != 4)
					   theMatrix[8].erase(theMatrix[8].end() - 2, theMatrix[8].end());
				   if ((theMatrix[positions[0][0]][positions[0][1]] == 6 || theMatrix[positions[0][0]][positions[0][1]] == -6) && ((positions[0][0] == 6 && positions[1][0] == 4) || (positions[0][0] == 1 && positions[1][0] == 3)))
				   {
					   theMatrix[8].push_back((positions[0][0] + positions[1][0]) / 2);
					   theMatrix[8].push_back(positions[0][1]);
				   }
				   //Ход
				   //castling
				   if (theMatrix[positions[0][0]][positions[0][1]] == 5)
				   {
					   if (positions[1][1] == positions[0][1] + 2)
					   {
						   theMatrix[0][7] = 0;
						   theMatrix[0][4] = 1;
					   }
					   if (positions[1][1] == positions[0][1] - 2)
					   {
						   theMatrix[0][0] = 0;
						   theMatrix[0][2] = 1;
					   }
				   }
				   if (theMatrix[positions[0][0]][positions[0][1]] == -5)
				   {
					   if (positions[1][1] == positions[0][1] + 2)
					   {
						   theMatrix[7][7] = 0;
						   theMatrix[7][4] = 1;
					   }
					   if (positions[1][1] == positions[0][1] - 2)
					   {
						   theMatrix[7][0] = 0;
						   theMatrix[7][2] = 1;
					   }
				   }
				   //Взятие на проходе
				   if (theMatrix[positions[0][0]][positions[0][1]] == 6 || theMatrix[positions[0][0]][positions[0][1]] == -6)
					   if (positions[1][1] != positions[0][1] && theMatrix[positions[1][0]][positions[1][1]] == 0)
						   theMatrix[positions[0][0]][positions[1][1]] = 0;
				   theMatrix[positions[1][0]][positions[1][1]] = theMatrix[positions[0][0]][positions[0][1]];
				   theMatrix[positions[0][0]][positions[0][1]] = 0;
				   //Ensuring rights of players to castle
				   if (theMatrix[0][0] == 0)
					   theMatrix[8][0] = 0;
				   if (theMatrix[0][7] == 0)
					   theMatrix[8][1] = 0;
				   if (theMatrix[0][3] == 0)
					   theMatrix[8][0] = theMatrix[8][1] = 0;
				   if (theMatrix[7][0] == 0)
					   theMatrix[8][2] = 0;
				   if (theMatrix[7][7] == 0)
					   theMatrix[8][3] = 0;
				   if (theMatrix[7][3] == 0)
					   theMatrix[8][2] = theMatrix[8][3] = 0;
//				   drawfield();
				   //Pawn at the end of the desk
				   if ((positions[1][0] == 7 || positions[1][0] == 0) && (theMatrix[positions[1][0]][positions[1][1]] == 6 || theMatrix[positions[1][0]][positions[1][1]] == -6))
				   {
					   theMatrix[positions[1][0]][positions[1][1]] = (positions[1][0] == 7) ? pawn_turnInto : -pawn_turnInto;
				   }
				   //Bot makes turn
				   if (!PvP)
				   {
					   if (check_mate(theMatrix, whites_turn) > 1)
					   {
						   positions = {};
						   return;
					   }
					   if ((playing_white && !whites_turn) || (!playing_white && whites_turn))
					   {
						   picked = !picked;
						   vector<int> theMove = bestMove(theMatrix, whites_turn);
						   if (theMove.size() != 0)
						   {
							   positions = { {theMove[0], theMove[1]}, {theMove[2], theMove[3]} };
						   }
//						   drawfield();
						   turn_made();
					   }
				   }
			   }
//			   else
//				   drawfield();
			   drawfield();
			   positions = {};
		   }
	   }
private: System::Void button66_Click(System::Object^ sender, System::EventArgs^ e) {
	pawn_turnInto = 4;
	label1->Text = L"Pawns'll turn into Queens";
}
private: System::Void button67_Click(System::Object^ sender, System::EventArgs^ e) {
	pawn_turnInto = 1;
	label1->Text = L"Pawns'll turn into Rooks";
}
private: System::Void button68_Click(System::Object^ sender, System::EventArgs^ e) {
	pawn_turnInto = 2;
	label1->Text = L"Pawns'll turn into Knights";
}
private: System::Void button69_Click(System::Object^ sender, System::EventArgs^ e) {
	pawn_turnInto = 3;
	label1->Text = L"Pawns'll turn into Bishops";
}
private: System::Void button70_Click(System::Object^ sender, System::EventArgs^ e) {
	playing_white = 1;
	PvP = 0;
}
private: System::Void button71_Click(System::Object^ sender, System::EventArgs^ e) {
	playing_white = 0;
	PvP = 0;
}
private: System::Void button72_Click(System::Object^ sender, System::EventArgs^ e) {
	PvP = 1;
}
};
}
