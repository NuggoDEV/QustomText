#include "main.hpp"
#include "QustomTextHooking.hpp"

#include "UnityEngine/UI/LayoutElement.hpp"
#include "System/Type.hpp"

#include "QustomTextConfig.hpp"
#include "UI/QustomTextUI.hpp"
using namespace QustomText;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/UI/Toggle.hpp"
using namespace UnityEngine;

DEFINE_TYPE(QustomText, QustomTextUI);

GameObject *centreContainer;
GameObject *leftContainer;
GameObject *rightContainer; 

bool screensEnabled = false;

void QustomTextUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {



    if (firstActivation) {
        centreContainer = BeatSaberUI::CreateScrollView(get_transform());
        leftContainer = BeatSaberUI::CreateFloatingScreen(Vector2(60.0f, 80.f), Vector3(-2.5f, 1.0f, 3.5f), Vector3(0.0f, -35.0f, 0.0f), 0.0f, true, false);
        rightContainer = BeatSaberUI::CreateFloatingScreen(Vector2(60.0f, 80.f), Vector3(2.5f, 1.0f, 3.5f), Vector3(0.0f, 35.0f, 0.0f), 0.0f, true, false);

        //Toggle Switches
        getLogger().info("Creating Toggle Switches");
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Text", getQustomTextConfig().ModToggle.GetValue(), Vector2(0.0f, -11.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Solo Text", getQustomTextConfig().SoloToggle.GetValue(), Vector2(0.0f, -18.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Multiplayer Text", getQustomTextConfig().MultiToggle.GetValue(), Vector2(0.0f, -25.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Campaign Text", getQustomTextConfig().CampaignToggle.GetValue(), Vector2(0.0f, -32.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Party Text", getQustomTextConfig().PartyToggle.GetValue(), Vector2(0.0f, -39.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Fail Text", getQustomTextConfig().FailToggle.GetValue(), Vector2(0.0f, -46.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Enable Qustom Pass Text", getQustomTextConfig().PassToggle.GetValue(), Vector2(0.0f, -53.0f), [](bool value) {});
        getLogger().info("Created Toggle Switches!");


        // String Creations
        getLogger().info("Creating Strings");
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().SoloText);
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().MultiText);
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().CampaignText);
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().PartyText);
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().FailText);
        AddConfigValueStringSetting(centreContainer->get_transform(), getQustomTextConfig().PassText);
        getLogger().info("Created Strings!");


        // Reset Text Buttons
        getLogger().info("Creating Reset Buttons");
        BeatSaberUI::CreateUIButton(rightContainer->get_transform(), "Reset Solo Text", Vector2(0.0f, -11.0f), []() {
            getQustomTextConfig().SoloText.SetValue("SOLO");
        });
    }

    if (!screensEnabled) {
        screensEnabled = true;
        centreContainer->SetActive(true);
        leftContainer->SetActive(true);
        rightContainer->SetActive(true);
    }
}

void QustomTextUI::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {
    screensEnabled = false;
    centreContainer->SetActive(false);
    leftContainer->SetActive(false);
    rightContainer->SetActive(false);

}