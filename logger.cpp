#include <iostream>

class Log{

    public:
        enum LEVEL
        {
            LevelInfo, LevelWarning, LevelError
        };
    private:
        int m_currentLogLevel = LevelError;

    public:
        void SetLevel(int level){
            m_currentLogLevel = level;
        }

        void Info(const char* message){
            if (m_currentLogLevel <= LevelInfo)
                std::cout<< " [LevelInfo] " << message <<std::endl;
        }

        void Warn(const char* message){
            if (m_currentLogLevel <= LevelWarning)
                std::cout<< " [LevelWarning] " << message <<std::endl;
        }

        void Error(const char* message){
            if (m_currentLogLevel <= LevelError)
                std::cout<< " [LevelError] " << message <<std::endl;
        }

};

int main(){
    Log log;
    log.SetLevel(Log::LevelError);
    log.Info("Hello");
    log.Warn("LevelWarning");
    log.Error("LevelError here");
    std::cin.get();
}