#pragma once
#include "WarehouseDashboard.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WareHouseForm 的摘要
	/// </summary>
	public ref class WareHouseForm : public System::Windows::Forms::Form
	{
	public:
		WareHouseForm(void)
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
		~WareHouseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;


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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 62);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Username: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 92);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 62);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(122, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(113, 92);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(122, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(258, 62);
			this->button1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 50);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Log In";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WareHouseForm::button1_Click);
			// 
			// WareHouseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 174);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"WareHouseForm";
			this->Text = L"Warehouse";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				WarehouseDashboard^ warehouseDashboard = gcnew WarehouseDashboard;
				warehouseDashboard->username = textBox1->Text;
				warehouseDashboard->password = textBox2->Text;
				 warehouseDashboard->Show();
	}
};
}
