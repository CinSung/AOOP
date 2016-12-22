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
			listBox1->Items->Add(" ");
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
		System::String ^logs;
		System::String ^selected;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
			 System::ComponentModel::Container ^components;
	public:
		property System::String^ username{
			System::String^ get(){
				return textBox1->Text;
			}
			void set(System::String^ text){
				textBox1->Text=text;
			}
		}
	public:
		property System::String^ password{
			System::String^ get(){
				return textBox2->Text;
			}
			void set(System::String^ text){
				textBox2->Text=text;
			}
		}
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(547, 73);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(672, 73);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Visible = false;
			// 
			// WarehouseDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 304);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->selectBox);
			this->Name = L"WarehouseDashboard";
			this->Text = L"WarehouseDashboard";
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
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		selected = selectBox->SelectedItem->ToString();
		listBox1->Items->Add(selected); 
		//if(selected != "")
			backgroundWorker2->RunWorkerAsync();				
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				
	}
	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			string password;
			string username;
			MarshalString ( textBox1->Text, username );
			MarshalString ( textBox2->Text, password );
				 
			MYSQL manager(username,password);
			vector <Supplier> suppliers = manager.getSupplier();
			vector <Product> products = manager.getProduct();
			string selectedCompany;
			long int productID;
			long int addedAmount;
			int i,k,itemAmount;
			MarshalString(selected,selectedCompany);
			bool found = false;
			for(i=0;i<suppliers.size();i++){
				if(selectedCompany == suppliers[i].getCompanyName()){
					productID = suppliers[i].getItemID();
					itemAmount = suppliers[i].getItemAmount();
					found = true;
					break;
				}
			}
			if(found){
				for(i=0;i<products.size();i++){
					if(products[i].getID() == productID){
						if(manager.updateProduct(products[i],itemAmount)){
							k = i;
							String ^ productName = gcnew String(products[k].getName().c_str());
							logs = "added "+System::Convert::ToString((int)products[k].getAmount()+itemAmount)+" to product: "+productName +" product id: "+System::Convert::ToString((int)products[k].getID());							
						}
						else{
							logs = "add failed";
						}
						break;				
					}
				}
			}
			else{
				logs = "failed to find the same object";
			}
			
	}
	private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		listBox1->Items->Add(logs);		  
	}
};
}
