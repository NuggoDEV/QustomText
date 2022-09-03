#include "main.hpp"
#include "QustomTextConfig.hpp"
#include "QustomTextHooking.hpp"

#include "UnityEngine/UI/Button.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

#include "HMUI/CurvedTextMeshPro.hpp"
using namespace HMUI;

#include "GlobalNamespace/MainMenuViewController.hpp"
using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self,bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    // SOLO BUTTON
    Button *soloMenuButton = self->soloButton;
    GameObject *soloGameObject = soloMenuButton->get_gameObject();
    CurvedTextMeshPro *soloMenuText = soloGameObject->GetComponentInChildren<CurvedTextMeshPro *>();

    if (!getQustomTextConfig().ModToggle.GetValue() && getQustomTextConfig().SoloToggle.GetValue()) {
        soloMenuText->SetText(getQustomTextConfig().SoloText.GetValue());
    }
    else {
        soloMenuText->SetText("SOLO");
    }


    // MULTI BUTTON
    Button *multiMenuButton = self->multiplayerButton;
    GameObject *multiGameObject = multiMenuButton->get_gameObject();
    CurvedTextMeshPro *multiMenuText = multiGameObject->GetComponentInChildren<CurvedTextMeshPro *>();

    if (!getQustomTextConfig().ModToggle.GetValue() && getQustomTextConfig().MultiToggle.GetValue()) {
        multiMenuText->SetText(getQustomTextConfig().MultiText.GetValue());
    }
    else {
        multiMenuText->SetText("MULTIPLAYER");
    }


    // CAMPAIGN BUTTON
    Button *campaignMenuButton = self->campaignButton;
    GameObject *campaignGameObject = campaignMenuButton->get_gameObject();
    CurvedTextMeshPro *campaignMenuText = campaignGameObject->GetComponentInChildren<CurvedTextMeshPro *>();

    
}