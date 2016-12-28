#include "MYSQL.h"
#include "Product.h"
#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PosUI
	/// </summary>
	public ref class PosUI : public System::Windows::Forms::Form
	{
	public:
		PosUI(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PosUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected: 
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		array <Int32>^ productID;
		array <String^>^productName;
		array <Double>^ priceForFew;
		String^ Password;
		String^ Username;
		Int32 array_size;
	private: System::Windows::Forms::Button^  Login;

	private: System::Windows::Forms::TextBox^  username;

	private: System::Windows::Forms::TextBox^  password;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Login = (gcnew System::Windows::Forms::Button());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(372, 47);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(259, 342);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PosUI::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(11, 47);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(45, 212);
			this->listBox2->TabIndex = 1;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(62, 47);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(162, 212);
			this->listBox3->TabIndex = 2;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(230, 47);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(64, 212);
			this->listBox4->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(230, 276);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"0.00";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(217, 324);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 47);
			this->button1->TabIndex = 5;
			this->button1->Text = L"checkout";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PosUI::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(114, 324);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(77, 47);
			this->button2->TabIndex = 6;
			this->button2->Text = L"clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PosUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(11, 324);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 47);
			this->button3->TabIndex = 7;
			this->button3->Text = L"remove last";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(161, 276);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Checkout";
			// 
			// Login
			// 
			this->Login->Location = System::Drawing::Point(372, 12);
			this->Login->Name = L"Login";
			this->Login->Size = System::Drawing::Size(75, 23);
			this->Login->TabIndex = 9;
			this->Login->Text = L"Login";
			this->Login->UseVisualStyleBackColor = true;
			this->Login->Click += gcnew System::EventHandler(this, &PosUI::Login_Click);
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(91, 15);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(100, 20);
			this->username->TabIndex = 11;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(261, 14);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(95, 20);
			this->password->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(202, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Username";
			// 
			// PosUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 411);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Controls->Add(this->Login);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Name = L"PosUI";
			this->Text = L"PosUI";
			this->Load += gcnew System::EventHandler(this, &PosUI::PosUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		void MarshalString ( String ^ s, string& os ) {  
			using namespace Runtime::InteropServices;  
			const char* chars =   
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
			os = chars;  
			Marshal::FreeHGlobal(IntPtr((void*)chars));  
		} 
		void fillProduct(){
			string username,password;
			MarshalString (Username , username );
			MarshalString (Password, password );
			MYSQL manager(username,password);
			vector <Product> productList = manager.getProduct();
			productID = gcnew array<Int32> (productList.size());
			productName = gcnew array<String^> (productList.size());
			priceForFew = gcnew array<Double> (productList.size());
			array_size = productList.size();
			for(int i=0;i<productList.size();i++){
				String ^ items = gcnew String(productList[i].getName().c_str());
				productName[i] = items;
				productID[i] = productList[i].getID();
				priceForFew[i] = productList[i].getPriceFew();
				items += "  "+System::Convert::ToString(productList[i].getPriceFew());				
				listBox1->Items->Add(items);
			}

		}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			// listBox1->Items->Clear();
			listBox2->Items->Clear();
			listBox3->Items->Clear();
			listBox4->Items->Clear();
			label1->Text = "0.00";
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ item = listBox1->SelectedItem->ToString();
			int i;
			Double sum = System::Convert::ToDouble(label1->Text);
			for(i=0;i < array_size;i++){
				if(item->Contains(productName[i])){
					listBox2->Items->Add(System::Convert::ToString(productID[i]));
					listBox3->Items->Add(productName[i]);
					listBox4->Items->Add(System::Convert::ToString(priceForFew[i]));
					sum += priceForFew[i];
					break;
				}
			}
			label1->Text = System::Convert::ToString(sum);
	}
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
        string username,password;
		MarshalString (Username , username );
		MarshalString (Password, password );
		MYSQL manager(username,password);
		string name;
		String^ result;
		 for(int i=0;i<listBox2->Items->Count-1;i++){
			result = listBox3->Items[i]->ToString();
			MarshalString (result , name );
			int id = System::Convert::ToInt32(listBox2->Items[i]->ToString());
			double price = System::Convert::ToDouble(listBox4->Items[i]->ToString());
			 //manager.addReceipt()
			manager.addReceipt(id,price,name);		 
		 }

	}
private: System::Void Login_Click(System::Object^  sender, System::EventArgs^  e) {
			Password = password->Text;
			Username = username->Text;
			fillProduct();
		 }
private: System::Void PosUI_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

};
}
