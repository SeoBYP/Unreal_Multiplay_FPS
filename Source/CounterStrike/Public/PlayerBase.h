// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "PlayerBase.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class COUNTERSTRIKE_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	void OnMove(const FInputActionValue& value);

	void OnLook(const FInputActionValue& value);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InputSystem;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess = "true"))
	UInputAction* LookAction; 

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess = "true"))
	float MouseHipTurnRate;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess = "true"))
	float MouseHipLookupRate;

public:
	UFUNCTION(BlueprintCallable)
	bool Initialize();
};
