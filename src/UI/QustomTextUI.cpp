#include "main.hpp"
#include "QustomTextHooking.hpp"

#include "UnityEngine/UI/LayoutElement.hpp"

#include "QustomTextConfig.hpp"
#include "UI/QustomTextUI.hpp"
using namespace QustomText;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

using namespace UnityEngine;

DEFINE_TYPE(QustomText, QustomTextUI);


void QustomTextUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    
    if (firstActivation) {
        GameObject *centreContainer = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
        GameObject *leftContainer = BeatSaberUI::CreateFloatingScreen(Vector2(45.0f, 20.f), Vector3(-2.0f, 0.0f, -2.3f), Vector3(45.0f, 0.0f, 0.0f), 0.0f, true, false);
        GameObject *rightContainer = BeatSaberUI::CreateFloatingScreen(Vector2(45.0f, 20.f), Vector3(2.0f, 0.0f, -2.3f), Vector3(-45.0f, 0.0f, 0.0f), 0.0f, true, false);

        AddConfigValueToggle(leftContainer->get_transform(), getQustomTextConfig().ModToggle)->get_gameObject();


    
    }    
}