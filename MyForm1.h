#pragma once
#include "Search.h"
#include "Sort.h"
#include "Movie.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <msclr\marshal_cppstd.h>

namespace DSAFinalUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		// JACK
		MyForm1(String^ year)
		{
			InitializeComponent();
			label1->Text = "Movies released in " + year;
			label6->Text = "Top 10 Movies in " + year + "\n";

			// String^ -> string
			string yearString = msclr::interop::marshal_as<string>(year);

			// Merge Sort
			Search movies1(yearString);
			auto begin = chrono::high_resolution_clock::now();
			mergeSort(movies1.searchmovieList, 0, movies1.searchmovieList.size() - 1);
			auto end = chrono::high_resolution_clock::now();
			auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

			string mergeTime = to_string(elapsed.count() * 1e-9);
			String^ timeM = gcnew String(mergeTime.c_str());

			label4->Text = timeM;

			// Quicksort
			Search movies2(yearString);
			begin = chrono::high_resolution_clock::now();
			quickSort(movies2.searchmovieList, 0, movies2.searchmovieList.size() - 1);
			end = chrono::high_resolution_clock::now();
			elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

			string quickTime = to_string(elapsed.count() * 1e-9);
			String^ timeQ = gcnew String(quickTime.c_str());

			label5->Text = timeQ;
			label7->Text = "";

			// Outputting Top 10 Movies
			for (int i = 0; i < 10; i++) {
				string text = movies1.searchmovieList[i].Print();
				String^ textS = gcnew String(text.c_str());
				label7->Text += (i+1) + ". " + textS;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Merge sort: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(193, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Quick sort: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(71, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"tms";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(249, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"tms";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 80);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"label7";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(349, 474);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm1";
			this->Text = L"Movies by Year";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
