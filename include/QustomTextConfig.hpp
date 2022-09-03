#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(QustomTextConfig, 

    CONFIG_VALUE(ModToggle, bool, "Disable Qustom Text", false);

    CONFIG_VALUE(SoloToggle, bool, "Enable Custom Solo Text", false);
    CONFIG_VALUE(MultiToggle, bool, "Enable Custom Multiplayer Text", false);
    CONFIG_VALUE(CampaignToggle, bool, "Enable Custom Campaign Text", false);
    CONFIG_VALUE(PartyToggle, bool, "Enable Custom Party Text", false);

    CONFIG_VALUE(FailToggle, bool, "Enable Custom Fail Text", false);
    CONFIG_VALUE(PassToggle, bool, "Enable Custom Pass Text", false);


    CONFIG_VALUE(SoloText, std::string, "Solo Button Text", "SOLO");
    CONFIG_VALUE(MultiText, std::string, "Multiplayer Button Text", "MULTIPLAYER");
    CONFIG_VALUE(CampaignText, std::string, "Campaign Button Text", "CAMPAIGN");
    CONFIG_VALUE(PartyText, std::string, "Party Button Text", "PARTY");

    CONFIG_VALUE(FailText, std::string, "Fail Screen Text", "LEVEL FAILED");
    CONFIG_VALUE(PassText, std::string, "Pass Screem Text", "LEVEL CLEARED");


    CONFIG_INIT_FUNCTION(

        CONFIG_INIT_VALUE(ModToggle);

        CONFIG_INIT_VALUE(SoloToggle);
        CONFIG_INIT_VALUE(MultiToggle);
        CONFIG_INIT_VALUE(CampaignToggle);
        CONFIG_INIT_VALUE(PartyToggle);

        CONFIG_INIT_VALUE(FailToggle);
        CONFIG_INIT_VALUE(PassToggle);


        CONFIG_INIT_VALUE(SoloText);
        CONFIG_INIT_VALUE(MultiText);
        CONFIG_INIT_VALUE(CampaignText);
        CONFIG_INIT_VALUE(PartyText);

        CONFIG_INIT_VALUE(FailText);
        CONFIG_INIT_VALUE(PassText);
    )
)