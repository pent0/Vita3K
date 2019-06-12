#include <gui/functions.h>
#include <gui/state.h>
#include <host/state.h>

namespace gui {

static constexpr float TROPHY_MOVE_DELTA = 12.0f;
static const ImVec2 TROPHY_WINDOW_SIZE = ImVec2(360, 80);
static constexpr int TROPHY_WINDOW_STATIC_FRAME_COUNT = 250;

static void draw_trophy_unlocked(HostState &host, NpTrophyUnlockCallbackData &callback_data) {
    if (host.gui.trophy_window_frame_stage == 0 || host.gui.trophy_window_frame_stage == 2) {
        ImVec2 target_window_pos = ImVec2(0.0f, 0.0f);
        
        if (host.gui.trophy_window_frame_stage == 0) 
            target_window_pos = ImVec2(ImGui::GetIO().DisplaySize.x - TROPHY_WINDOW_SIZE.x - 10.0f, 20.0f);
        else
            target_window_pos = ImVec2(ImGui::GetIO().DisplaySize.x + 10, 20);

        if (host.gui.trophy_window_frame_stage == 0 && host.gui.trophy_window_frame_count == 0) {
            host.gui.trophy_window_pos = ImVec2(ImGui::GetIO().DisplaySize.x + 10, 20);

            // Load icon
            host.gui.trophy_window_icon = load_image(host, (const char*)callback_data.icon_buf.data(),
                static_cast<std::uint32_t>(callback_data.icon_buf.size()));
        } else if (host.gui.trophy_window_frame_stage == 0 && host.gui.trophy_window_pos.x > target_window_pos.x) {
            host.gui.trophy_window_pos.x -= TROPHY_MOVE_DELTA;
        } else if (host.gui.trophy_window_frame_stage == 2 && host.gui.trophy_window_pos.x < target_window_pos.x) {
            host.gui.trophy_window_pos.x += TROPHY_MOVE_DELTA;
        } else {
            host.gui.trophy_window_frame_stage++;
            host.gui.trophy_window_frame_count = 0;
        }
    
        host.gui.trophy_window_frame_count++;
    }

    ImGui::SetNextWindowBgAlpha(0.9f);
    ImGui::SetNextWindowPos(host.gui.trophy_window_pos);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10);
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.76f, 0.75f, 0.76f, 1.0f));    // Smooth gray
    ImGui::SetNextWindowSize(TROPHY_WINDOW_SIZE);
    ImGui::Begin("##NoName", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
    ImGui::SetWindowFontScale(1.3f);
    ImGui::SetCursorPos(ImVec2(10.0f, 10.0f));
    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnWidth(0, 80.0f);
    ImGui::Image((ImTextureID)host.gui.trophy_window_icon, ImVec2(60.0f, 60.0f));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.24f, 0.24f, 0.24f, 1.0f));
    ImGui::NextColumn();

    std::string trophy_kind_s = "?";

    switch (callback_data.trophy_kind) {
    case emu::np::trophy::TrophyType::PLATINUM: {
        trophy_kind_s = "P";
        break;
    }

    case emu::np::trophy::TrophyType::BRONZE: {
        trophy_kind_s = "B";
        break;
    }
    
    case emu::np::trophy::TrophyType::SLIVER: {
        trophy_kind_s = "S";
        break;
    }
    
    case emu::np::trophy::TrophyType::GOLD: {
        trophy_kind_s = "P";
        break;
    }

    default:
        break;
    }

    ImGui::Text("%s (%s)", callback_data.trophy_name.c_str(), trophy_kind_s.c_str());
    ImGui::Text("%s", callback_data.description.c_str());

    ImGui::PopStyleColor();
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    ImGui::PopStyleVar();

    if (host.gui.trophy_window_frame_stage == 1) {
        host.gui.trophy_window_frame_count++;

        if (host.gui.trophy_window_frame_count == TROPHY_WINDOW_STATIC_FRAME_COUNT) {
            host.gui.trophy_window_frame_stage = 2;
            host.gui.trophy_window_frame_count = 0;
        }
    }
}

void draw_trophies_unlocked(HostState &host) {
    const std::lock_guard<std::mutex> guard(host.gui.trophy_unlock_display_requests_access_mutex);

    if (!host.gui.trophy_unlock_display_requests.empty()) {
        if (host.gui.trophy_window_frame_stage == 3) {
            host.gui.trophy_unlock_display_requests.pop();

            // Destroy the texture
            if (host.gui.trophy_window_frame_count != 0xFFFFFFFF)
                destroy_image(host.gui.trophy_window_icon);

            host.gui.trophy_window_frame_stage = 0;
            host.gui.trophy_window_frame_count = 0;
        } else {
            draw_trophy_unlocked(host, host.gui.trophy_unlock_display_requests.back());
        }
    }
}

}