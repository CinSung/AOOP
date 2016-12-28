#pragma once
#include "MYSQL.h"
#include "Supplier.h"
#include "Staffs.h"
#include <vector>
#include <string>
using namespace std;

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Staff 的摘要
	/// </summary>
	public ref class Staff : public System::Windows::Forms::Form
	{
	public:
		Staff(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Staff()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
//	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Username: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(80, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(157, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 25);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(157, 150);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(161, 25);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(356, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Log In";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Staff::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(83, 191);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(468, 200);
			this->textBox3->TabIndex = 5;
			// 
			// Staff
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 435);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Staff";
			this->Text = L"Staff";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void hide_login_and_showinfo()
		{
			textBox1->Visible=false;
			textBox2->Visible=false;
			label1->Visible=false;
			label2->Visible=false;
			button1->Visible=false;
		}
		 

#pragma endregion
		void MarshalString ( String ^ s, string& os ) {  
			using namespace Runtime::InteropServices;  
			const char* chars =   
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			os = chars;  
			Marshal::FreeHGlobal(IntPtr((void*)chars));  
		}  

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 bool success=1;

				 string usr,pwd;
				 MarshalString(textBox1->Text,usr);
				 MarshalString(textBox2->Text,pwd);
				 MYSQL staffdata(usr,pwd);

				 vector <Staffs> staffs=staffdata.getStaff() ;

				 //string name;
				 //string pos;
				 //unsigned int sal;
				 
				 for (int i=0;i<staffs.size();i++)
				 {
					 //textBox3->Text+="a";
					 String ^temp = gcnew String(staffs[i].getname().c_str());
					 textBox3->Text+=temp;
					 delete [] temp;

					 temp = gcnew String(staffs[i].getposition().c_str());
					 textBox3->Text+="\t"+temp;
					 delete [] temp;

					 temp = System::Convert::ToString(staffs[i].getsalary());
					 textBox3->Text+="\t"+temp+"\r\n";

					 //+"\t"+staffs[i].getposition()+"\t"+System::Convert::ToString(staffs[i].getsalary())+"\r\n";
				 }
	 
				 if (!success)	return;
				 hide_login_and_showinfo();
			 }
};
}
