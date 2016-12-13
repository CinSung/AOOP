#pragma once
#include <string>
#include <iostream>
#include "Supplier.h"
#include "PurchaseManage.h"
#include <vector>
using namespace std;
namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 ���K�n
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  username;
	private: System::Windows::Forms::TextBox^  password;

	private: System::Windows::Forms::ListBox^  listBox1;


	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void MarshalString ( String ^ s, string& os ) {  
			using namespace Runtime::InteropServices;  
			const char* chars =   
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			os = chars;  
			Marshal::FreeHGlobal(IntPtr((void*)chars));  
		}  
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(410, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"sync";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(31, 13);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(100, 20);
			this->username->TabIndex = 1;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(239, 12);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(100, 20);
			this->password->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(31, 51);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(362, 173);
			this->listBox1->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 261);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^ buffer;
				 string user,pass,name;
//				 listBox1->Items->Add(password->Text);
//				 listBox1->Items->Add(username->Text);
				 MarshalString(password->Text,pass);
				 MarshalString(username->Text,user);
				 PurchaseManage manager(user,pass);
				 vector <Supplier> list = manager.getSupplierList();

				 for(int i=0;i < list.size();i++){

					 buffer = gcnew String(list[i].getCompanyName().c_str());
					listBox1->Items->Add(buffer);
				 }
	 }
};
}

