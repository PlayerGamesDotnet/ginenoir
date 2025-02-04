#pragma once

#include <Core/Physics/SurfaceResourceDescriptor.h>
#include <Foundation/Types/RangeView.h>
#include <Foundation/Types/SharedPtr.h>
#include <ParticlePlugin/Events/ParticleEventReaction.h>

class EZ_PARTICLEPLUGIN_DLL ezParticleEventReactionFactory_Effect final : public ezParticleEventReactionFactory
{
  EZ_ADD_DYNAMIC_REFLECTION(ezParticleEventReactionFactory_Effect, ezParticleEventReactionFactory);

public:
  ezParticleEventReactionFactory_Effect();

  virtual const ezRTTI* GetEventReactionType() const override;
  virtual void CopyReactionProperties(ezParticleEventReaction* pObject, bool bFirstTime) const override;

  virtual void Save(ezStreamWriter& inout_stream) const override;
  virtual void Load(ezStreamReader& inout_stream) override;

  ezString m_sEffect;
  ezEnum<ezSurfaceInteractionAlignment> m_Alignment;

  //////////////////////////////////////////////////////////////////////////
  // Exposed Parameters
public:
  const ezRangeView<const char*, ezUInt32> GetParameters() const;
  void SetParameter(const char* szKey, const ezVariant& value);
  void RemoveParameter(const char* szKey);
  bool GetParameter(const char* szKey, ezVariant& out_value) const;

private:
  ezSharedPtr<ezParticleEffectParameters> m_pParameters;
};

class EZ_PARTICLEPLUGIN_DLL ezParticleEventReaction_Effect final : public ezParticleEventReaction
{
  EZ_ADD_DYNAMIC_REFLECTION(ezParticleEventReaction_Effect, ezParticleEventReaction);

public:
  ezParticleEventReaction_Effect();
  ~ezParticleEventReaction_Effect();

  ezParticleEffectResourceHandle m_hEffect;
  ezEnum<ezSurfaceInteractionAlignment> m_Alignment;
  ezSharedPtr<ezParticleEffectParameters> m_Parameters;

protected:
  virtual void ProcessEvent(const ezParticleEvent& e) override;
};
