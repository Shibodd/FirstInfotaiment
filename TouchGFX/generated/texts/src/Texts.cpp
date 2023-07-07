/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x53, 0x70, 0x65, 0x63, 0x69, 0x61, 0x6c, 0x20, 0x54, 0x68, 0x61, 0x6e, 0x6b, 0x73, 0x20, 0x74, 0x6f, 0x3a, 0xa, 0x46, 0x61, 0x74, 0x74, 0x6f, 0x72, 0x65, 0x20, 0x47, 0x2c, 0xa, 0x46, 0x61, 0x74, 0x74, 0x6f, 0x72, 0x65, 0x20, 0x42, 0x2c, 0xa, 0x46, 0x61, 0x74, 0x74, 0x6f, 0x72, 0x65, 0x20, 0x4d, 0x0, // @0 "Special Thanks to:\nFattore G,\nFattore B,\nFattore M"
    0x53, 0x65, 0x6c, 0x65, 0x63, 0x74, 0x20, 0x4d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x0, // @51 "Select Mission"
    0x43, 0x68, 0x61, 0x73, 0x73, 0x69, 0x73, 0xa, 0x52, 0x65, 0x73, 0x65, 0x74, 0x0, // @66 "Chassis\nReset"
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x25, 0x2e, 0x0, // @80 "1234567890%."
    0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @93 "Acceleration"
    0x2, 0x20, 0x62, 0x61, 0x72, 0x0, // @106 "<> bar"
    0x2, 0x20, 0x6b, 0x6d, 0x68, 0x0, // @112 "<> kmh"
    0x4c, 0x41, 0x50, 0x20, 0x2, 0x0, // @118 "LAP <>"
    0x2, 0x20, 0xb0, 0x43, 0x0, // @124 "<> ?C"
    0x41, 0x75, 0x74, 0x6f, 0x6e, 0x6f, 0x6d, 0x6f, 0x75, 0x73, 0x0, // @129 "Autonomous"
    0x49, 0x6e, 0x73, 0x70, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @140 "Inspection"
    0x54, 0x72, 0x61, 0x63, 0x6b, 0x64, 0x72, 0x69, 0x76, 0x65, 0x0, // @151 "Trackdrive"
    0x2, 0x20, 0x56, 0x0, // @162 "<> V"
    0x41, 0x75, 0x74, 0x6f, 0x63, 0x72, 0x6f, 0x73, 0x73, 0x0, // @166 "Autocross"
    0x42, 0x61, 0x74, 0x74, 0x65, 0x72, 0x79, 0x5f, 0x56, 0x0, // @176 "Battery_V"
    0x45, 0x6d, 0x65, 0x72, 0x67, 0x65, 0x6e, 0x63, 0x79, 0x0, // @186 "Emergency"
    0x2, 0x25, 0x0, // @196 "<>%"
    0x45, 0x42, 0x53, 0x20, 0x54, 0x65, 0x73, 0x74, 0x0, // @199 "EBS Test"
    0x45, 0x62, 0x73, 0x20, 0x74, 0x65, 0x73, 0x74, 0x0, // @208 "Ebs test"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @217 "New Text"
    0x50, 0x20, 0x42, 0x72, 0x61, 0x6b, 0x65, 0x0, // @226 "P Brake"
    0x53, 0x6b, 0x69, 0x64, 0x70, 0x61, 0x64, 0x0, // @234 "Skidpad"
    0x54, 0x5f, 0x77, 0x61, 0x74, 0x65, 0x72, 0x0, // @242 "T_water"
    0x42, 0x61, 0x74, 0x20, 0x31, 0x32, 0x0, // @250 "Bat 12"
    0x42, 0x61, 0x74, 0x20, 0x32, 0x34, 0x0, // @257 "Bat 24"
    0x4d, 0x61, 0x6e, 0x75, 0x61, 0x6c, 0x0, // @264 "Manual"
    0x50, 0x20, 0x46, 0x75, 0x65, 0x6c, 0x0, // @271 "P Fuel"
    0x54, 0x20, 0x4f, 0x72, 0x69, 0x6e, 0x0, // @278 "T Orin"
    0x31, 0x30, 0x30, 0x30, 0x30, 0x0, // @285 "10000"
    0x31, 0x32, 0x30, 0x30, 0x30, 0x0, // @291 "12000"
    0x44, 0x65, 0x62, 0x75, 0x67, 0x0, // @297 "Debug"
    0x50, 0x20, 0x4f, 0x69, 0x6c, 0x0, // @303 "P Oil"
    0x50, 0x5f, 0x6f, 0x69, 0x6c, 0x0, // @309 "P_oil"
    0x54, 0x20, 0x4d, 0x6f, 0x74, 0x0, // @315 "T Mot"
    0x54, 0x20, 0x4f, 0x69, 0x6c, 0x0, // @321 "T Oil"
    0x54, 0x5f, 0x6f, 0x69, 0x6c, 0x0, // @327 "T_oil"
    0x30, 0x2e, 0x30, 0x30, 0x0, // @333 "0.00"
    0x30, 0x30, 0x2e, 0x30, 0x0, // @338 "00.0"
    0x31, 0x32, 0x2e, 0x30, 0x0, // @343 "12.0"
    0x32, 0x34, 0x2e, 0x30, 0x0, // @348 "24.0"
    0x49, 0x64, 0x6c, 0x65, 0x0, // @353 "Idle"
    0x4e, 0x6f, 0x6e, 0x65, 0x0, // @358 "None"
    0x54, 0x6f, 0x69, 0x6c, 0x0, // @363 "Toil"
    0x31, 0x30, 0x30, 0x0, // @368 "100"
    0x31, 0x32, 0x56, 0x0, // @372 "12V"
    0x32, 0x34, 0x56, 0x0, // @376 "24V"
    0x41, 0x4d, 0x49, 0x0, // @380 "AMI"
    0x43, 0x4c, 0x54, 0x0, // @384 "CLT"
    0x45, 0x42, 0x53, 0x0, // @388 "EBS"
    0x4b, 0x4d, 0x48, 0x0, // @392 "KMH"
    0x4c, 0x41, 0x50, 0x0, // @396 "LAP"
    0x4f, 0x66, 0x66, 0x0, // @400 "Off"
    0x52, 0x45, 0x53, 0x0, // @404 "RES"
    0x52, 0x50, 0x4d, 0x0, // @408 "RPM"
    0x54, 0x50, 0x53, 0x0, // @412 "TPS"
    0x31, 0x33, 0x0, // @416 "13"
    0x41, 0x53, 0x0, // @419 "AS"
    0x44, 0x53, 0x0, // @422 "DS"
    0x4c, 0x43, 0x0, // @425 "LC"
    0x31, 0x0, // @428 "1"
    0x35, 0x0, // @430 "5"
    0x4e, 0x0 // @432 "N"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
