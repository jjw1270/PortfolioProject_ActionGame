// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Cpt_FootIK.h"

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInst_PlayerCharacter.generated.h"

UCLASS()
class ACTIONGAME1_API UAnimInst_PlayerCharacter : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAnimInst_PlayerCharacter();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	//! IK Component Init
	void Init_IKFootRef();

	//! IK Component Tick
	void Tick_IKFoot();

	//! IK Component Ref 
	UPROPERTY()
	TObjectPtr<class UCpt_FootIK> m_pIK_Foot_Ref;

	//! IK Component Animvalue struct
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "IKFoot Value", meta = (AllowPrivateAccess = "true"))
	FST_IK_AnimValue m_stIKAnimValue;
};
