#pragma once
#include "Staff1.h"
#include "StoreInfo.h"
#include "Account1.h"
#include "SaleSystemForm.h"
#include "WareHouseForm.h"
#include "PosUI.h"


namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainWindow 的摘要
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		//Form^ StaffForm;
		//Form^ StoreInfoForm;
		//Form^ AccountForm;
		//Form^ SaleForm ;
		//Form^ WarehouseForm;
		//Form^ posui
		Form^ NewForm;
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(149, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(500, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L"員工管理";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(149, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(500, 75);
			this->button2->TabIndex = 1;
			this->button2->Text = L"超商資料";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(149, 182);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(500, 75);
			this->button3->TabIndex = 2;
			this->button3->Text = L"帳目";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(149, 263);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(500, 75);
			this->button4->TabIndex = 3;
			this->button4->Text = L"銷售服務";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainWindow::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(149, 344);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(500, 75);
			this->button5->TabIndex = 4;
			this->button5->Text = L"倉儲管理";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainWindow::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(149, 426);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(500, 75);
			this->button6->TabIndex = 5;
			this->button6->Text = L"倉儲管理";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainWindow::button6_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainWindow::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainWindow::backgroundWorker1_RunWorkerCompleted);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(781, 555);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 NewForm = gcnew Staff;
				 NewForm->Show();

				 this->Enabled=false;
				 backgroundWorker1->RunWorkerAsync();
				 
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				NewForm = gcnew StoreInfo;
				NewForm->Show();

				this->Enabled=false;
				backgroundWorker1->RunWorkerAsync();

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				NewForm = gcnew Account;
				NewForm->Show();

				this->Enabled=false;
				backgroundWorker1->RunWorkerAsync();

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				NewForm = gcnew SaleSystemForm;
				NewForm->Show();

				this->Enabled=false;
				backgroundWorker1->RunWorkerAsync();

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				NewForm = gcnew WareHouseForm;
				NewForm->Show();

				this->Enabled=false;
				backgroundWorker1->RunWorkerAsync();

		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				NewForm = gcnew PosUI;
				NewForm->Show();

				this->Enabled=false;
				backgroundWorker1->RunWorkerAsync();

		 }
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 while (NewForm->Created){}
		 }
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 this->Enabled=true;
		 }
};
}
