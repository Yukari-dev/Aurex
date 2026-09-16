#pragma once
#include <filesystem>
#include <optional>
#include <string>

namespace Aurex{

class FileWatcher{
public:
  explicit FileWatcher(const std::string& path);

  bool Changed();
private:
  std::string m_path{};
  std::filesystem::file_time_type m_lastSeen{};
  std::optional<std::filesystem::file_time_type> m_pending{};
};

}
