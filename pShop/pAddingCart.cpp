#include "pAddingCart.h"
#include "pAddCart.h"

System::Decimal Cost;

System::Void pShop::pAddingCart::pAddingCart_Load(System::Object^ sender, System::EventArgs^ e)
{
    pShop::pAddCart::ConfirmAdd = false;
    Cost = nudCost->Value;
    return System::Void();
}

System::Void pShop::pAddingCart::nudWeight_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    nudCost->Value = nudWeight->Value * Cost;
}

System::Void pShop::pAddingCart::nudValue_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    nudCost->Value = nudValue->Value * Cost;
}

System::Void pShop::pAddingCart::btnAddCartConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
    pShop::pAddCart::ConfirmAdd = true;
    this->Close();
}
