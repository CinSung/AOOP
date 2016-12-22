#pragma once
#include "MYSQL.h"
#include "Supplier.h"
using namespace std;


namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WarehouseDashboard
	/// </summary>
	public ref class WarehouseDashboard : public System::Windows::Forms::Form
	{
	public:
		WarehouseDashboard(void)
		{
			InitializeComponent();
			MYSQL manager("root","aoop2016");
			vector <Supplier> suppliers = manager.getSupplier();
			selectBox->BeginUpdate();
			for(int i=0;i<suppliers.size();i++){
				String ^ buffer = gcnew String(suppliers[i].getCompanyName().c_str());
				selectBox->Items->Add(buffer);
			}
			selectBox->EndUpdate();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WarehouseDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  selectBox;
	protected: 

	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		String ^logs;
		String ^selected;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->selectBox = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// selectBox
			// 
			this->selectBox->FormattingEnabled = true;
			this->selectBox->Location = System::Drawing::Point(23, 32);
			this->selectBox->Name = L"selectBox";
			this->selectBox->Size = System::Drawing::Size(228, 21);
			this->selectBox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(279, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Order";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WarehouseDashboard::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(407, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 37);
			this->button2->TabIndex = 2;
			this->button2->Text = L"ShowProfile";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &WarehouseDashboard::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(23, 100);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(481, 186);
			this->listBox1->TabIndex = 3;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &WarehouseDashboard::backgroundWorker2_DoWork);
			// 
			// WarehouseDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 304);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->selectBox);
			this->Name = L"WarehouseDashboard";
			this->Text = L"WarehouseDashboard";
			this->ResumeLayout(false);

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
		selected = System::Converted(selectBox->SelectedItem;
		if(selected != "")
			backgroundWorker2->RunWorkerAsync();				
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				
	}
	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			MYSQL manager("root","aoop2016");
			vector <Supplier> suppliers = manager.getSupplier();
			vector <Product> products = manager.getProduct();
			string selectedCompany;
			long int productID;
			long int addedAmount;
			MarshalString(selected,selectedCompany);
			for(int i=0;i<suppliers.size();i++){
				if(selectedCompany == suppliers[i].getCompanyName()){
					productID = suppliers[i].getID();
					break;
				}
			}
			for(int i=0;i<products.size();i++){
				if(products[i].getID() == productID){
					
				}
			}
	}
};
}
