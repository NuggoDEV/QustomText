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
        leftContainer = BeatSaberUI::CreateFloatingScreen(Vector2(60.0f, 80.f), Vector3(-2.0f, 1.0f, 3.5f), Vector3(0.0f, -35.0f, 0.0f), 0.0f, true, false);
        rightContainer = BeatSaberUI::CreateFloatingScreen(Vector2(60.0f, 80.f), Vector3(2.0f, 1.0f, 3.5f), Vector3(0.0f, 35.0f, 0.0f), 0.0f, true, false);

        // All of the Toggle Switches
        getLogger().info("Creating Toggle Switches");

        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Text", getQustomTextConfig().ModToggle.GetValue(), Vector2(0.0f, 0.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Solo Text", getQustomTextConfig().SoloToggle.GetValue(), Vector2(0.0f, -7.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Multiplayer Text", getQustomTextConfig().MultiToggle.GetValue(), Vector2(0.0f, -14.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Campaign Text", getQustomTextConfig().CampaignToggle.GetValue(), Vector2(0.0f, -21.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Party Text", getQustomTextConfig().PartyToggle.GetValue(), Vector2(0.0f, -28.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Fail Text", getQustomTextConfig().FailToggle.GetValue(), Vector2(0.0f, -35.0f), [](bool value) {});
        BeatSaberUI::CreateToggle(leftContainer->get_transform(), "Disable Qustom Pass Text", getQustomTextConfig().PassToggle.GetValue(), Vector2(0.0f, -42.0f), [](bool value) {});


        // Other String Stuff
        UnityEngine::Transform *parent = centreContainer->get_transform();
        auto layout = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(parent);
        layout->GetComponent<UnityEngine::UI::LayoutElement *>()->set_preferredWidth(50.0f);
        auto layoutParent = layout->get_transform();

        // String Creations
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().SoloText);
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().MultiText);
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().CampaignText);
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().PartyText);
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().FailText);
        AddConfigValueStringSetting(layoutParent, getQustomTextConfig().PassText);
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