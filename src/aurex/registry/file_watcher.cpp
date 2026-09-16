#include "aurex/registry/file_watcher.hpp"

namespace Aurex{

FileWatcher::FileWatcher(const std::string& path) : m_path(std::move(path)){
  std::error_code ec;
  m_lastSeen = std::filesystem::last_write_time(m_path, ec);
}

bool FileWatcher::Changed(){
  std::error_code ec;
  auto current = std::filesystem::last_write_time(m_path, ec);

  if(ec) return false;

  if(current == m_lastSeen)
    return false;

  if(m_pending && *m_pending == current){
    m_lastSeen = current;
    m_pending.reset();   
  }

  m_pending = current;
  return true;
}

}
